#include "AlgoOCR_CodeReview.h"
#include "QTextCodec"
#include "QFileInfo"
#include "QTime"
#include "QCoreApplication"
#include "opencv2/opencv.hpp"
#include "BoxPacked.h"//����ǹ֧����
#include "SinglePacked.h"//����ǹ֧����

using namespace std;
using namespace cv;

CAlgoCodeReview *CAlgoCodeReview::m_Instance = NULL;
CAlgoCodeReview::GarbageCollection CAlgoCodeReview::m_Collection;

CAlgoCodeReview::CAlgoCodeReview(QObject *parent /* = NULL */)
	:QObject(parent)
{
	m_bInitSuccess = false;
	m_CurModel = DEFAULT_MODEL;//Ĭ�ϼ�
	m_OcrModules.insert(DEFAULT_MODEL, new VimoOCRModule());//��ֵ��
	m_OcrModules.insert(RIFLE_MODEL95, new VimoOCRModule());
	m_OcrModules.insert(RIFLE_MODEL951, new VimoOCRModule());
	m_OcrModules.insert(PISTOL_MODEL54, new VimoOCRModule());
	m_OcrModules.insert(PISTOL_MODEL92, new VimoOCRModule());
	m_OcrModules.insert(RIFLE_MODEL81, new VimoOCRModule());
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



//���õ�ǰǹ֧����
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
		case PISTOL_MODEL92:
			ModulePath = "Shouqiang92.smartmore";
			break;
		case RIFLE_MODEL81:
			ModulePath = "Buqiang81.smartmore";
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

	//std::vector<std::vector<cv::Point >> contours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]
	//
	//for (int i = 0; i < rsp.blocks.size(); ++i)
	//{

	//	std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
	//	TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
	//	for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
	//	{
	//		Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
	//		cv::Point p;
	//		if (j < 2)
	//		{
	//			p.x = coord.x;
	//			p.y = coord.y +50;
	//		}
	//		else
	//		{
	//			p.x = coord.x;
	//			p.y = coord.y;
	//		}
	//		
	//		
	//		contour.push_back(p);
	//	}
	//	contours.push_back(contour);
	//	
	//}

	////cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	//maskImage = Mat::zeros(image.rows, image.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	cv::drawContours(maskImage, contours, i, Scalar(255), -1);//����mask����
	//}
	///*namedWindow("mask", 0);*/
	////cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ

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
	case PISTOL_MODEL92:
		PistolModel92();
		result = Myresult;
		break;
	case RIFLE_MODEL81:
		RifleModel81();
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

	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]

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
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ

	Mat element = getStructuringElement(MORPH_RECT, Size(40, 3));//�Զ����
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//���ʹ���
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

//void CAlgoCodeReview::RifleModel951()
//{
//
//	Mat element = getStructuringElement(MORPH_RECT, Size(25, 5));//�Զ����
//	Mat ROIImage;
//
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//���ʹ���
//	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//	/*imshow("ԭͼ", maskImage);
//	imshow("��̬ѧ������ͼ", ROIImage);*/
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  
//
//	//�����������
//	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.
//
//	/*imshow("ɸѡͼ", ROIImage);
//	waitKey(1);*/
//
//	vector<vector<cv::Point >> contours1;
//	std::vector<TextBlock> blocks;
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//		TextBlock Tblock = rsp.blocks[i];
//		double distance = pointPolygonTest(contours[largest_contour_index], Point2f(Tblock.polygon[0].x, Tblock.polygon[0].y), true);
//		if (distance >= 0)
//		{
//			blocks.push_back(Tblock);
//		}
//			
//	}
//	sort(blocks.begin(), blocks.end(), [](TextBlock b1, TextBlock b2) {return b1.polygon[0].x < b2.polygon[0].x; });
//	for (int i = 0; i < 6; i++)
//	{
//		auto b = blocks[i];
//		string ocrText = b.text;
//		cv::Point p(b.polygon[0].x, b.polygon[0].y);
//		cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
//		Myresult += QString::fromStdString(b.text);
//
//		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
//		for (int j = 0; j < 4; j++)
//		{
//			contour.push_back(cv::Point(b.polygon[j].x, b.polygon[j].y));
//		}
//		contours1.push_back(contour);
//	}
//	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
//
//}

//951ʽ��ǹ
void CAlgoCodeReview::RifleModel951()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]

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
		stringContours.push_back(contour);

	}

	//cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ


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
				if (Myresult.size() != 6)
				{
					Myresult += QString::fromStdString(Tblock.text);
					cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
				}
				//if (ocrText != "-" && Myresult.size() != 6)
				//{
				//	Myresult += QString::fromStdString(Tblock.text);
				//	cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
				//}

			}

			contour.push_back(p);
		}
		contours1.push_back(contour);
	}
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}

void CAlgoCodeReview::PistolModel54()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]

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
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ

	Mat element = getStructuringElement(MORPH_RECT, Size(35, 3));//�Զ����
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 3);//���ʹ���
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
	qDebug() << "Myresult:" << Myresult;
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}

//92ʽ��ǹ
//void CAlgoCodeReview::PistolModel92()
//{
//
//	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]
//
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//
//		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
//		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
//		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
//		{
//			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
//			cv::Point p;
//			if (j < 2)
//			{
//				p.x = coord.x;
//				p.y = coord.y + 50;
//			}
//			else
//			{
//				p.x = coord.x;
//				p.y = coord.y;
//			}
//
//
//			contour.push_back(p);
//		}
//		stringContours.push_back(contour);
//
//	}
//
//	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���
//
//	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
//	for (int i = 0; i < stringContours.size(); i++)
//	{
//		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
//	}
//	/*namedWindow("mask", 0);*/
//	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ
//
//	Mat element = getStructuringElement(MORPH_RECT, Size(10, 2));//�Զ����
//	Mat ROIImage;
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//���ʹ���
//	cv::threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//
//	namedWindow("ԭͼ", 0);
//	resizeWindow("ԭͼ", 640, 480);
//	imshow("ԭͼ", maskImage);
//
//	namedWindow("��̬ѧ������ͼ", 0);
//	resizeWindow("��̬ѧ������ͼ", 640, 480);
//	imshow("��̬ѧ������ͼ", ROIImage);
//
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  
//
//	//����ROI��Ӿ���
//	vector<RotatedRect> box(contours.size());
//	Point2f rect[4];
//	float max_y = 0.0;
//	int roi_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//	double roiArea;//��ͨ�����
//	double contourLength;
//	cv::Point centrepoint;
//	for (int i = 0; i < contours.size(); i++)
//	{
//		roiArea = contourArea(contours[i]);
//		contourLength = arcLength(contours[i], true);
//		if (roiArea > 20000 && roiArea < 32000 && contourLength>900 && contourLength < 1200)
//		{
//			box[i] = minAreaRect(Mat(contours[i]));
//
//			centrepoint.x = box[i].center.x;
//			centrepoint.y = box[i].center.y;
//			if (centrepoint.y > max_y)
//			{
//				max_y = centrepoint.y;
//				roi_index = i;
//			}
//
//
//		}
//
//
//	}
//
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, roi_index, Scalar(255), -1);
//	namedWindow("ɸѡͼ", 0);
//	resizeWindow("ɸѡͼ", 640, 480);
//	imshow("ɸѡͼ", ROIImage);
//	waitKey(1);
//
//	vector<vector<cv::Point >> contours1;
//	std::vector<TextBlock> Codeblocks;
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//		TextBlock Tblock = rsp.blocks[i];
//		double distance = pointPolygonTest(contours[roi_index], Point2f(Tblock.polygon[2].x, Tblock.polygon[2].y), true);
//		if (distance >= 0)
//		{
//			Codeblocks.push_back(Tblock);
//		}
//	}
//	sort(Codeblocks.begin(), Codeblocks.end(), [](TextBlock b1, TextBlock b2) {return b1.polygon[0].x < b2.polygon[0].x; });
//
//	if (Codeblocks.size() > 6)
//	{
//		for (int i = 1; i <= 6; i++)
//		{
//			auto b = Codeblocks[i];
//			string ocrText = b.text;
//			cv::Point p(b.polygon[0].x, b.polygon[0].y);
//			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
//			Myresult += QString::fromStdString(b.text);
//
//			std::vector<cv::Point > contour;
//			for (int j = 0; j < 4; j++)
//			{
//				contour.push_back(cv::Point(b.polygon[j].x, b.polygon[j].y));
//			}
//			contours1.push_back(contour);
//		}
//		cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
//	}
//	else
//	{
//		vector<vector<cv::Point >> contours1;
//		for (int i = 0; i < rsp.blocks.size(); ++i)
//		{
//			std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
//			TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
//
//			for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
//			{
//				Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
//
//				cv::Point p;
//				p.x = coord.x;
//				p.y = coord.y;
//
//				if (j == 0)
//				{
//					cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
//					Myresult += QString::fromStdString(Tblock.text);
//
//				}
//				contour.push_back(p);
//			}
//
//			contours1.push_back(contour);
//		}
//		qDebug() << "Myresult:" << Myresult;
//		cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
//	}
//
//}

void CAlgoCodeReview::PistolModel92()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//����Ϊ[0,0],���帡������������[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//��i���ַ���Χ��
		for (int j = 0; j < Tblock.polygon.size(); ++j)//�����ַ���Χ�еĶ��������������˳ʱ��˳�����У���һ�������ǰ�Χ�е����Ͻ�,����Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  ��άƽ����ߵ�һ���� float x, y; ���Ͻ�������Tblock.polygon.at(0)
			cv::Point p;
			if (j < 2)
			{
				p.x = coord.x;
				p.y = coord.y + 30;
			}
			else
			{
				p.x = coord.x;
				p.y = coord.y;
			}


			contour.push_back(p);
		}
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ

	Mat element = getStructuringElement(MORPH_RECT, Size(60, 2));//�Զ����
	Mat ROIImage;
	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//���ʹ���
	cv::threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("ԭͼ", 0);
	resizeWindow("ԭͼ", 640, 480);
	imshow("ԭͼ", maskImage);

	namedWindow("��̬ѧ������ͼ", 0);
	resizeWindow("��̬ѧ������ͼ", 640, 480);
	imshow("��̬ѧ������ͼ", ROIImage);*/

	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  

	//������С��Ӿ������ݺ������
	vector<RotatedRect> box(contours.size());
	Point2f rect[4];
	int maxRatio = 0;
	int maxNum = 0;
	double roiArea;//��ͨ�����
	for (int i = 0; i < contours.size(); i++)
	{
		//roiArea = contourArea(contours[i]);

		box[i] = minAreaRect(Mat(contours[i]));

		int maxSide, minSide, width, height;
		width = box[i].size.width;
		height = box[i].size.height;
		maxSide = (width > height) ? width : height;
		minSide = (width < height) ? width : height;
		if (maxSide / minSide > maxRatio)
		{
			maxRatio = maxSide / minSide;
			maxNum = i;
		}

	}

	ROIImage.setTo(0);
	drawContours(ROIImage, contours, maxNum, Scalar(255), -1);
	/*namedWindow("ɸѡͼ", 0);
	resizeWindow("ɸѡͼ", 640, 480);
	imshow("ɸѡͼ", ROIImage);
	waitKey(1);*/

	vector<vector<cv::Point >> contours1;
	std::vector<TextBlock> Codeblocks;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		TextBlock Tblock = rsp.blocks[i];
		double distance = pointPolygonTest(contours[maxNum], Point2f(Tblock.polygon[2].x, Tblock.polygon[2].y), true);
		if (distance >= 0)
		{
			Codeblocks.push_back(Tblock);
		}
	}
	sort(Codeblocks.begin(), Codeblocks.end(), [](TextBlock b1, TextBlock b2) {return b1.polygon[0].x < b2.polygon[0].x; });

	if (Codeblocks.size() > 6)
	{
		for (int i = 0; i <= 6; i++)
		{
			auto b = Codeblocks[i];
			string ocrText = b.text;
			cv::Point p(b.polygon[0].x, b.polygon[0].y);
			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
			Myresult += QString::fromStdString(b.text);

			std::vector<cv::Point > contour;
			for (int j = 0; j < 4; j++)
			{
				contour.push_back(cv::Point(b.polygon[j].x, b.polygon[j].y));
			}
			contours1.push_back(contour);
		}
		cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
	}
	else
	{
		for (int i = 0; i < Codeblocks.size(); i++)
		{
			auto b = Codeblocks[i];

			string ocrText = b.text;
			cv::Point p(b.polygon[0].x, b.polygon[0].y);
			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
			Myresult += QString::fromStdString(b.text);

			std::vector<cv::Point > contour;
			for (int j = 0; j < 4; j++)
			{
				contour.push_back(cv::Point(b.polygon[j].x, b.polygon[j].y));
			}
			contours1.push_back(contour);
		}
		qDebug() << "Myresult:" << Myresult;
		cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);


	}

}

//81ʽ��ǹ
void CAlgoCodeReview::RifleModel81()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours�����ά����������,���ҵ��ı߽�ģ�x,y�����괢�ҵ��ı߽�ģ�x,y������ �磺[1,2;2,3;3,4]

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
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//��2���������Բ���contour����contours������     //����λ���

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //����һ�ź�ɫ��ͼ
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//����mask����
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//���Ƶİ�Χ�ж�ֵͼ


	//�����ͨ��
	Mat element = getStructuringElement(MORPH_RECT, Size(50, 2));//�Զ����
	Mat ROIImage;
	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//���ʹ���
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("ԭͼ", 0);
	resizeWindow("ԭͼ", 640, 480);
	imshow("ԭͼ", maskImage);

	namedWindow("��̬ѧ������ͼ", 0);
	resizeWindow("��̬ѧ������ͼ", 640, 480);
	imshow("��̬ѧ������ͼ", ROIImage);*/


	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  

	//������С��Ӿ������ݺ������
	//vector<Rect> boundRect(contours.size());
	vector<RotatedRect> box(contours.size());
	Point2f rect[4];
	int maxRatio = 0;
	int maxNum;
	for (int i = 0; i < contours.size(); i++)
	{
		box[i] = minAreaRect(Mat(contours[i]));

		int maxSide, minSide, width, height;
		width = box[i].size.width;
		height = box[i].size.height;
		maxSide = (width > height) ? width : height;
		minSide = (width < height) ? width : height;

		if (maxSide / minSide > maxRatio)
		{
			maxRatio = maxSide / minSide;
			maxNum = i;
		}

	}

	ROIImage.setTo(0);
	drawContours(ROIImage, contours, maxNum, Scalar(255), -1);

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

			double distance = pointPolygonTest(contours[maxNum], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			if (j == 0 && distance >= 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//��ͼƬ�ϻ�������
				Myresult += QString::fromStdString(Tblock.text);

			}
			contour.push_back(p);
		}

		contours1.push_back(contour);
	}
	qDebug() << "Myresult:" << Myresult;
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
}



//��ѡ81ʽ��ǹ
//void CAlgoCodeReview::RifleModel81()
//{
//
//	Mat element = getStructuringElement(MORPH_RECT, Size(50, 2));//�Զ����
//	Mat ROIImage;
//
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//���ʹ���
//	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//
//	namedWindow("ԭͼ", 0);
//	resizeWindow("ԭͼ", 640, 480);
//	imshow("ԭͼ", maskImage);
//
//	namedWindow("��̬ѧ������ͼ", 0);
//	resizeWindow("��̬ѧ������ͼ", 640, 480);
//	imshow("��̬ѧ������ͼ", ROIImage);
//
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // ������������Ӧ��ͨ��  
//
//	//������С����
//	auto least_contour_index = min_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, least_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.
//
//	namedWindow("ɸѡͼ", 0);
//	resizeWindow("ɸѡͼ", 640, 480);
//	imshow("ɸѡͼ", ROIImage);
//	waitKey(1);
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
//			double distance = pointPolygonTest(contours[least_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
//			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
//			if (j==0 && distance >= 0)
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
//}
