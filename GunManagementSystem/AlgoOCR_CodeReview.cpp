#include "AlgoOCR_CodeReview.h"
#include "QTextCodec"
#include "QFileInfo"
#include "QTime"
#include "QCoreApplication"

CAlgoCodeReview *CAlgoCodeReview::m_Instance = NULL;
CAlgoCodeReview::GarbageCollection CAlgoCodeReview::m_Collection;

CAlgoCodeReview::CAlgoCodeReview(QObject *parent /* = NULL */)
	:QObject(parent)
{
	m_bInitSuccess = false;
}

CAlgoCodeReview::~CAlgoCodeReview()
{
}

CAlgoCodeReview *CAlgoCodeReview::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CAlgoCodeReview();
	}
	return m_Instance;
}

bool CAlgoCodeReview::InitAlgo()
{
	QString path = QCoreApplication::applicationDirPath();
	//path += "/module/ocrVersion_1.smartmore";
	path += "/module/OCRVersion.smartmore";
	
	QByteArray ba = path.toLocal8Bit();
	char *file = ba.data();
	ResultCode rv = m_OcrModule.Init(file, 1, 0);
	m_bInitSuccess = rv == ResultCode::Success;
	return m_bInitSuccess;
}

bool CAlgoCodeReview::RunAlog(Mat &image, QString &result)
{
	OCRRequest req;
	req.image = image;
	req.threshold = 0.7;
	OCRResponse rsp;
	ResultCode rv = m_OcrModule.Run(req, rsp);
	if (rv != ResultCode::Success)
	{
		return false;
	}
	if (rsp.blocks.size() == 0)
	{
		return false;
	}
	std::vector<std::vector<cv::Point >> contours;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;
		TextBlock Tblock = rsp.blocks.at(i);
		result += QString::fromStdString(Tblock.text);
		for (int j = 0; j < Tblock.polygon.size(); ++j)
		{
			Coordinate coord = Tblock.polygon.at(j);
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;
			if (j == 0)
			{
				cv::putText(image, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
			}
			contour.push_back(p);
		}
		contours.push_back(contour);
	}
	cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可
	//cv::fillPoly(temp, contours, cv::Scalar(255, 255, 255));//fillPoly函数的第二个参数是二维数组！！
// 	cv::namedWindow("test", WINDOW_NORMAL);
// 	cv::imshow("test", temp);
// 	waitKey();
	return true;
}