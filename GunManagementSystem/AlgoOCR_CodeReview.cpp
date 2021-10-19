#include "AlgoOCR_CodeReview.h"
#include "QTextCodec"
#include "QFileInfo"
#include "QTime"
#include "QCoreApplication"
#include "opencv2/opencv.hpp"
//#include "SystemManager.h"//����ǹ֧����
#include "BoxPacked.h"//����ǹ֧����
#include "SinglePacked.h"//����ǹ֧����

using namespace std;

CAlgoCodeReview *CAlgoCodeReview::m_Instance = NULL;
CAlgoCodeReview::GarbageCollection CAlgoCodeReview::m_Collection;

CAlgoCodeReview::CAlgoCodeReview(QObject *parent /* = NULL */)
	:QObject(parent)
{
	m_bInitSuccess = false;
	m_CurModel = DEFAULT_MODEL;//Ĭ�ϼ��ǡ�����
	m_OcrModules.insert(DEFAULT_MODEL, new VimoOCRModule());//��ֵ��
	m_OcrModules.insert(RIFLE_MODEL95, new VimoOCRModule());
	m_OcrModules.insert(RIFLE_MODEL951, new VimoOCRModule());
	m_OcrModules.insert(PISTOL_MODEL54, new VimoOCRModule());
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


////����ǹ֧ģ��
//bool CAlgoCodeReview::SetGunModel(e_GunModel type)
//{
//	m_GunModel = type;
//	return true;
//
//}

void CAlgoCodeReview::SetGunModel(e_GunModel GunModel)
{
	m_CurModel = GunModel;
}


/**
			SDK��ʼ��
			@param  input_model_path ��ģ��·��
			@param  USE_GPU             ���Ƿ�ʹ��gpu
			@param  device_id         ���豸id
			@return ������ ��0���ɹ��� ����ֵ��ʧ��
		*/
bool CAlgoCodeReview::InitAlgo()
{
	bool bAllOK = true;
	MapGunModle_OCRModule::iterator it = m_OcrModules.begin(), itEnd = m_OcrModules.end();
	for (; it != itEnd; ++it)
	{

		QString path = QCoreApplication::applicationDirPath();
		path += "/model/";

		e_GunModel Model = it.key();
		VimoOCRModule *OCRModule = it.value();
		QString ModulePath = NULL;
		switch (Model)
		{
		case DEFAULT_MODEL:
			
			//ģ��·��

			ModulePath = "Default.smartmore";
			break;
		case RIFLE_MODEL95:
			ModulePath = "Buqiang95.smartmore";
			break;

		case RIFLE_MODEL951:
			ModulePath = "Buqiang951.smartmore";
			break;

		case PISTOL_MODEL54:
			ModulePath = "Shouqiang54.smartmore";
			break;
		}
		path += ModulePath;
		QByteArray ba = path.toLocal8Bit();
		char *file = ba.data();
		
		ResultCode rv = OCRModule->Init(file, 1, 0);
		if (rv != ResultCode::Success)
		{
			//����
			bAllOK = false;
		}
	}
	return bAllOK;
}


bool CAlgoCodeReview::RunAlog(Mat &image, QString &result)
{
	OCRRequest req;//SDK������
	req.image = image;
	req.threshold = 0.7;

	VimoOCRModule *CurOCRModule = m_OcrModules[m_CurModel];//��ǰģ��
	//OCRResponse rsp;//OCR��������run�����ĳ���
	ResultCode rv = CurOCRModule->Run(req, rsp);  //ResultCode SDKģ��  ����OCR���󣬲��ڷ�������д��������
	if (rv != ResultCode::Success)
	{
		return false;
	}
	if (rsp.blocks.size() == 0)//�жϰ�Χ�еĸ���
	{
		return false;
	}
	//string a=rsp.blocks[0].text;
	OrigenImage = image;
	
	std::vector<std::vector<cv::Point >> contours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;
			
			contour.push_back(p);
		}
		contours.push_back(contour);
		
	}

	//cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(image.rows, image.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < contours.size(); i++)
	{
		cv::drawContours(maskImage, contours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ

	Myresult.clear();
	switch (m_CurModel)//��ǰģ��
	{
	case DEFAULT_MODEL:

		DefaultModel();
		result = Myresult;
		break;
	case RIFLE_MODEL95:

		RifleModel95();
		result = Myresult;
		break;

	case RIFLE_MODEL951:

		RifleModel951();
		result = Myresult;
		break;

	case PISTOL_MODEL54:
		PistolModel54();
		result = Myresult;
		break;
	}

	return true;
}



void CAlgoCodeReview::DefaultModel()
{
	vector<vector<cv::Point >> contours;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
		Myresult += QString::fromStdString(Tblock.text);
		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;
			if (j == 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
			}
			contour.push_back(p);
		}
		contours.push_back(contour);

	}
	cv::polylines(OrigenImage, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
	
}


void CAlgoCodeReview::RifleModel95()
{
	vector<vector<cv::Point >> contours;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
		Myresult += QString::fromStdString(Tblock.text);
		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;
			if (j == 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
			}
			contour.push_back(p);
		}
		contours.push_back(contour);

	}
	cv::polylines(OrigenImage, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}


void CAlgoCodeReview::RifleModel951()
{
	
	Mat element = getStructuringElement(MORPH_RECT, Size(25, 5));//�Զ����
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//���ʹ���
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
	/*imshow("ԭͼ", maskImage);
	imshow("��̬ѧ������ͼ", ROIImage);*/
	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  

	//�����������
	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
	ROIImage.setTo(0);
	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.

	/*imshow("ɸѡͼ", ROIImage);
	waitKey(1);*/

	vector<vector<cv::Point >> contours1;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��

		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			//Coordinate coord0 = Tblock.polygon.at(0);
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;


			double distance = pointPolygonTest(contours[largest_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
			if (j == 0 && distance > 0)
			{
				string ocrText;
				ocrText = Tblock.text;
				if (ocrText!="-" && Myresult.size()!=6)
				{
					Myresult += QString::fromStdString(Tblock.text);
					cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
				}
				
			}

			contour.push_back(p);
		}
		contours1.push_back(contour);
	}
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}


void CAlgoCodeReview::PistolModel54()
{
	
	Mat element = getStructuringElement(MORPH_RECT, Size(25, 5));//�Զ����
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//���ʹ���
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
	
	/*namedWindow("ԭͼ", 0);
	resizeWindow("ԭͼ", 640, 480);
	imshow("ԭͼ", maskImage);

	namedWindow("��̬ѧ������ͼ", 0);
	resizeWindow("��̬ѧ������ͼ", 640, 480);
	imshow("��̬ѧ������ͼ", ROIImage);*/

	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  

	//�����������
	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();

	ROIImage.setTo(0);
	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.

	//namedWindow("ɸѡͼ", 0);
	//resizeWindow("ɸѡͼ", 640, 480);
	//imshow("ɸѡͼ", ROIImage);
	//waitKey(1);

	vector<vector<cv::Point >> contours1;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��

		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			double distance = pointPolygonTest(contours[largest_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
			if (j == 0 && distance > 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
				Myresult += QString::fromStdString(Tblock.text);

			}

			contour.push_back(p);
		}
		contours1.push_back(contour);
	}
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}


//��ѡ81ʽ��ǹ
//void CAlgoCodeReview::RifleModel81()
//{
//
//	
//	Mat element = getStructuringElement(MORPH_RECT, Size(50, 5));//�Զ����
//	Mat ROIImage;
//
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//���ʹ���
//	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//
////	namedWindow("ԭͼ", 0);
////	resizeWindow("ԭͼ", 640, 480);
////	imshow("ԭͼ", maskImage);
////
////	namedWindow("��̬ѧ������ͼ", 0);
////	resizeWindow("��̬ѧ������ͼ", 640, 480);
////	imshow("��̬ѧ������ͼ", ROIImage);
//
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  
//
//	//�����������
//	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.
//
////	namedWindow("ɸѡͼ", 0);
////	resizeWindow("ɸѡͼ", 640, 480);
////	imshow("ɸѡͼ", ROIImage);
////	waitKey(1);
//
//	vector<vector<cv::Point >> contours1;
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
//		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
//
//		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
//		{
//			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
//			//Coordinate coord0 = Tblock.polygon.at(0);
//			cv::Point p;
//			p.x = coord.x;
//			p.y = coord.y;
//
//
//			double distance = pointPolygonTest(contours[largest_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
//			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
//			if (j == 0 && distance > 0)
//			{
//				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
//				Myresult += QString::fromStdString(Tblock.text);
//
//
//			}
//
//			contour.push_back(p);
//		}
//		contours1.push_back(contour);
//	}
//	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
//
//
//}