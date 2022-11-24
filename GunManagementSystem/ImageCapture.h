#pragma once
#include <QThread>
#include <QMutex>
#include "MvCamera.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CImageCapture :public QThread
{
	Q_OBJECT
public:
	CImageCapture(QThread *parent = NULL);
	~CImageCapture();
	bool SetCameraHandle(CMvCamera &camera);
	void SetCameraStatus(bool bOpen);
	void StopThread();




private:
	CMvCamera m_MvCamera;
	QMutex m_Mutex;
	bool m_bOpen;
	bool m_bStop;
	unsigned char*  m_pGrabBuf;
	unsigned int nDataSize;

private:
	void run();
	cv::Mat Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData);
	cv::Mat img;
	cv::Mat curImage;


signals:
	void SendCaptureImage(Mat img);
};
