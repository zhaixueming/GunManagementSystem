#include <QDebug>
#include <QTextCodec>
#include "windows.h"
#include "ImageCapture.h"


CImageCapture::CImageCapture(QThread *parent /* = NULL */)
	:QThread(parent)
{
	m_bOpen = false;
	m_bStop = false;
	m_pGrabBuf = NULL;
}

CImageCapture::~CImageCapture()
{
}

int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight)
{
	if (NULL == pRgbData)
	{
		return MV_E_PARAMETER;
	}

	for (unsigned int j = 0; j < nHeight; j++)
	{
		for (unsigned int i = 0; i < nWidth; i++)
		{
			unsigned char red = pRgbData[j * (nWidth * 3) + i * 3];
			pRgbData[j * (nWidth * 3) + i * 3] = pRgbData[j * (nWidth * 3) + i * 3 + 2];
			pRgbData[j * (nWidth * 3) + i * 3 + 2] = red;
		}
	}

	return MV_OK;
}

cv::Mat CImageCapture::Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData)
{
	cv::Mat srcImage;
	if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
		return cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
	}
	else if(pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		return cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
	}
	else
	{
		//�����ͼ���ʽת��ΪRGB8_Packed
		unsigned char *pDataForRGB = (unsigned char*)malloc(pstImageInfo->nWidth * pstImageInfo->nHeight * 3);
		unsigned int nDataSizeForRGB = pstImageInfo->nWidth * pstImageInfo->nHeight * 3;
		MV_CC_PIXEL_CONVERT_PARAM pstCvtParam = { 0 };
		memset(&pstCvtParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
		pstCvtParam.enSrcPixelType = pstImageInfo->enPixelType;
		pstCvtParam.nWidth = pstImageInfo->nWidth;
		pstCvtParam.nHeight = pstImageInfo->nHeight;
		pstCvtParam.pSrcData = pData;
		pstCvtParam.nSrcDataLen = pstImageInfo->nFrameLen;
		pstCvtParam.enDstPixelType = PixelType_Gvsp_RGB8_Packed;
		pstCvtParam.pDstBuffer = pDataForRGB;
		pstCvtParam.nDstBufferSize = nDataSizeForRGB;
		int nRet = m_MvCamera.ConvertPixelType(&pstCvtParam);
		if (nRet != MV_OK)
		{
			qDebug() << "Hik ConvertImageType failed :" << nRet;
			return srcImage;
		}

		RGB2BGR(pDataForRGB, pstImageInfo->nWidth, pstImageInfo->nHeight);
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pDataForRGB).clone();
		delete pDataForRGB;
		pDataForRGB = NULL;
		return srcImage;
	}

#if 0
	if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
	}
	else if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
		srcImage = cv::Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
	}
	else
	{
		qDebug() << "unsupported pixel format";
	}

	if (NULL == srcImage.data)
	{
		qDebug() << "srcImage.data is NULL";
	}
	return srcImage;
#endif
}

bool CImageCapture::SetCameraHandle(CMvCamera &camera)
{
	m_MvCamera = camera;
	MVCC_INTVALUE_EX stIntValue = { 0 };
	int nRet = m_MvCamera.GetIntValue("PayloadSize", &stIntValue);
	if (nRet != MV_OK)
	{
		qDebug() << "failed in get PayloadSize:" << nRet;
		return false;
	}
	nDataSize = (unsigned int)stIntValue.nCurValue;
	if (m_pGrabBuf != NULL)
	{
		delete m_pGrabBuf;
		m_pGrabBuf = NULL;
	}
	m_pGrabBuf = (unsigned char *)malloc(sizeof(unsigned char) * nDataSize);
	if (m_pGrabBuf == NULL)
	{
		qDebug() << "malloc grab buffer failed";
		return false;
	}
	return true;
}

void CImageCapture::SetCameraStatus(bool bOpen)
{
	m_Mutex.lock();
	m_bOpen = bOpen;
	m_Mutex.unlock();
}

void CImageCapture::StopThread()
{
	m_Mutex.lock();
	m_bStop = true;
	m_Mutex.unlock();
}

void CImageCapture::run()
{
	int nRet = MV_OK;
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	while (1)
	{
		m_Mutex.lock();
		bool bStop = m_bStop;
		bool bOpen = m_bOpen;
		m_Mutex.unlock();
		if (bStop)
		{
			break;
		}
		if (bOpen)
		{
			int nRet = m_MvCamera.GetOneFrameTimeout(m_pGrabBuf, nDataSize, &stImageInfo, 1000);
			if (nRet == MV_OK)
			{
				cv::Mat img = Convert2Mat(&stImageInfo, m_pGrabBuf);
				if (img.data == NULL)
				{
					continue;
				}
				cv::Mat curImage = img.clone();
				emit SendCaptureImage(curImage);
			}
		}
		else
		{
			Sleep(10);
		}
	}
	if (m_pGrabBuf != NULL)
	{
		delete m_pGrabBuf;
		m_pGrabBuf = NULL;
	}
}