#include "AlgoOCR_CodeReview.h"
#include "QTextCodec"
#include "QFileInfo"
#include "QTime"
#include "QCoreApplication"
#include "opencv2/opencv.hpp"
#include "BoxPacked.h"//用于枪支类型
#include "SinglePacked.h"//用于枪支类型

using namespace std;
using namespace cv;

CAlgoCodeReview *CAlgoCodeReview::m_Instance = NULL;
CAlgoCodeReview::GarbageCollection CAlgoCodeReview::m_Collection;

CAlgoCodeReview::CAlgoCodeReview(QObject *parent /* = NULL */)
	:QObject(parent)
{
	m_bInitSuccess = false;
	m_CurModel = DEFAULT_MODEL;//默认键
	m_OcrModules.insert(DEFAULT_MODEL, new VimoOCRModule());//键值对
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



//设置当前枪支类型
void CAlgoCodeReview::SetGunModel(e_GunModel GunModel)
{
	m_CurModel = GunModel;
}


/**
			SDK初始化
			@param  input_model_path ：模型路径
			@param  USE_GPU             ：是否使用gpu
			@param  device_id         ：设备id
			@return 返回码 ：0：成功； 其他值：失败
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

			//模型路径

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
			//报错
			bAllOK = false;
		}
	}
	return bAllOK;
}


bool CAlgoCodeReview::RunAlog(Mat &image, QString &result)
{
	OCRRequest req;//SDK的输入
	req.image = image;
	req.threshold = 0.7;
	VimoOCRModule *CurOCRModule = m_OcrModules[m_CurModel];//当前模型
	//OCRResponse rsp;//OCR推理结果，run函数的出参
	ResultCode rv = CurOCRModule->Run(req, rsp);  //ResultCode SDK模型  接受OCR请求，并在返回体中写入推理结果
	if (rv != ResultCode::Success)
	{
		return false;
	}
	if (rsp.blocks.size() == 0)//判断包围盒的个数
	{
		return false;
	}
	//string a=rsp.blocks[0].text;
	OrigenImage = image;

	//std::vector<std::vector<cv::Point >> contours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]
	//
	//for (int i = 0; i < rsp.blocks.size(); ++i)
	//{

	//	std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
	//	TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
	//	for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
	//	{
	//		Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
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

	////cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	//maskImage = Mat::zeros(image.rows, image.cols, CV_8UC1); //创建一张黑色的图
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	cv::drawContours(maskImage, contours, i, Scalar(255), -1);//绘制mask轮廓
	//}
	///*namedWindow("mask", 0);*/
	////cv::imshow("mask", maskImage);//绘制的包围盒二值图

	Myresult.clear();
	switch (m_CurModel)//当前模型
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

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		Myresult += QString::fromStdString(Tblock.text);
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;
			if (j == 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
			}
			contour.push_back(p);
		}
		contours.push_back(contour);

	}
	cv::polylines(OrigenImage, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}


void CAlgoCodeReview::RifleModel95()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			contour.push_back(p);
		}
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//绘制的包围盒二值图

	Mat element = getStructuringElement(MORPH_RECT, Size(40, 3));//自定义核
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//膨胀处理
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("原图", 0);
	resizeWindow("原图", 640, 480);
	imshow("原图", maskImage);

	namedWindow("形态学处理结果图", 0);
	resizeWindow("形态学处理结果图", 640, 480);
	imshow("形态学处理结果图", ROIImage);*/

	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  

	//查找最大轮廓
	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();

	ROIImage.setTo(0);
	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.

	//namedWindow("筛选图", 0);
	//resizeWindow("筛选图", 640, 480);
	//imshow("筛选图", ROIImage);
	//waitKey(1);

	vector<vector<cv::Point >> contours1;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒

		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			double distance = pointPolygonTest(contours[largest_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
			if (j == 0 && distance > 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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
//	Mat element = getStructuringElement(MORPH_RECT, Size(25, 5));//自定义核
//	Mat ROIImage;
//
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//膨胀处理
//	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//	/*imshow("原图", maskImage);
//	imshow("形态学处理结果图", ROIImage);*/
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  
//
//	//查找最大轮廓
//	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.
//
//	/*imshow("筛选图", ROIImage);
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
//		cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
//		Myresult += QString::fromStdString(b.text);
//
//		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
//		for (int j = 0; j < 4; j++)
//		{
//			contour.push_back(cv::Point(b.polygon[j].x, b.polygon[j].y));
//		}
//		contours1.push_back(contour);
//	}
//	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
//
//}

//951式步枪
void CAlgoCodeReview::RifleModel951()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			contour.push_back(p);
		}
		stringContours.push_back(contour);

	}

	//cv::polylines(image, contours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//绘制的包围盒二值图


	Mat element = getStructuringElement(MORPH_RECT, Size(25, 5));//自定义核
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 1);//膨胀处理
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
	/*imshow("原图", maskImage);
	imshow("形态学处理结果图", ROIImage);*/
	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  

	//查找最大轮廓
	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
	ROIImage.setTo(0);
	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.

	/*imshow("筛选图", ROIImage);
	waitKey(1);*/

	vector<vector<cv::Point >> contours1;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒

		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
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
					cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
				}
				//if (ocrText != "-" && Myresult.size() != 6)
				//{
				//	Myresult += QString::fromStdString(Tblock.text);
				//	cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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

	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			contour.push_back(p);
		}
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//绘制的包围盒二值图

	Mat element = getStructuringElement(MORPH_RECT, Size(35, 3));//自定义核
	Mat ROIImage;

	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 3);//膨胀处理
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("原图", 0);
	resizeWindow("原图", 640, 480);
	imshow("原图", maskImage);

	namedWindow("形态学处理结果图", 0);
	resizeWindow("形态学处理结果图", 640, 480);
	imshow("形态学处理结果图", ROIImage);*/

	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  

	//查找最大轮廓
	auto largest_contour_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();

	ROIImage.setTo(0);
	drawContours(ROIImage, contours, largest_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.

	//namedWindow("筛选图", 0);
	//resizeWindow("筛选图", 640, 480);
	//imshow("筛选图", ROIImage);
	//waitKey(1);

	vector<vector<cv::Point >> contours1;
	for (int i = 0; i < rsp.blocks.size(); ++i)
	{
		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒

		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			double distance = pointPolygonTest(contours[largest_contour_index], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			//ROIImage.at<float>(p.x, p.y) = static_cast<float>(distance);
			if (j == 0 && distance > 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
				Myresult += QString::fromStdString(Tblock.text);

			}

			contour.push_back(p);
		}

		contours1.push_back(contour);
	}
	qDebug() << "Myresult:" << Myresult;
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

}

//92式手枪
//void CAlgoCodeReview::PistolModel92()
//{
//
//	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]
//
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//
//		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
//		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
//		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
//		{
//			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
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
//	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制
//
//	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
//	for (int i = 0; i < stringContours.size(); i++)
//	{
//		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
//	}
//	/*namedWindow("mask", 0);*/
//	//cv::imshow("mask", maskImage);//绘制的包围盒二值图
//
//	Mat element = getStructuringElement(MORPH_RECT, Size(10, 2));//自定义核
//	Mat ROIImage;
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//膨胀处理
//	cv::threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//
//	namedWindow("原图", 0);
//	resizeWindow("原图", 640, 480);
//	imshow("原图", maskImage);
//
//	namedWindow("形态学处理结果图", 0);
//	resizeWindow("形态学处理结果图", 640, 480);
//	imshow("形态学处理结果图", ROIImage);
//
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  
//
//	//查找ROI外接矩形
//	vector<RotatedRect> box(contours.size());
//	Point2f rect[4];
//	float max_y = 0.0;
//	int roi_index = max_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//	double roiArea;//连通域面积
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
//	namedWindow("筛选图", 0);
//	resizeWindow("筛选图", 640, 480);
//	imshow("筛选图", ROIImage);
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
//			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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
//			std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
//			TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
//
//			for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
//			{
//				Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
//
//				cv::Point p;
//				p.x = coord.x;
//				p.y = coord.y;
//
//				if (j == 0)
//				{
//					cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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

	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
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

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//绘制的包围盒二值图

	Mat element = getStructuringElement(MORPH_RECT, Size(60, 2));//自定义核
	Mat ROIImage;
	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//膨胀处理
	cv::threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("原图", 0);
	resizeWindow("原图", 640, 480);
	imshow("原图", maskImage);

	namedWindow("形态学处理结果图", 0);
	resizeWindow("形态学处理结果图", 640, 480);
	imshow("形态学处理结果图", ROIImage);*/

	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  

	//查找最小外接矩形中纵横比最大的
	vector<RotatedRect> box(contours.size());
	Point2f rect[4];
	int maxRatio = 0;
	int maxNum = 0;
	double roiArea;//连通域面积
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
	/*namedWindow("筛选图", 0);
	resizeWindow("筛选图", 640, 480);
	imshow("筛选图", ROIImage);
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
			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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
			cv::putText(OrigenImage, b.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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

//81式步枪
void CAlgoCodeReview::RifleModel81()
{

	std::vector<std::vector<cv::Point >> stringContours;//contours定义二维浮点型向量,储找到的边界的（x,y）坐标储找到的边界的（x,y）坐标 如：[1,2;2,3;3,4]

	for (int i = 0; i < rsp.blocks.size(); ++i)
	{

		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			contour.push_back(p);
		}
		stringContours.push_back(contour);

	}

	//cv::polylines(image, stringContours, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);//第2个参数可以采用contour或者contours，均可     //多边形绘制

	maskImage = Mat::zeros(OrigenImage.rows, OrigenImage.cols, CV_8UC1); //创建一张黑色的图
	for (int i = 0; i < stringContours.size(); i++)
	{
		cv::drawContours(maskImage, stringContours, i, Scalar(255), -1);//绘制mask轮廓
	}
	/*namedWindow("mask", 0);*/
	//cv::imshow("mask", maskImage);//绘制的包围盒二值图


	//获得连通域
	Mat element = getStructuringElement(MORPH_RECT, Size(50, 2));//自定义核
	Mat ROIImage;
	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//膨胀处理
	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);

	/*namedWindow("原图", 0);
	resizeWindow("原图", 640, 480);
	imshow("原图", maskImage);

	namedWindow("形态学处理结果图", 0);
	resizeWindow("形态学处理结果图", 640, 480);
	imshow("形态学处理结果图", ROIImage);*/


	vector<vector<cv::Point >> contours; // Vector for storing contours
	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  

	//查找最小外接矩形中纵横比最大的
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
		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒

		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
		{
			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)

			cv::Point p;
			p.x = coord.x;
			p.y = coord.y;

			double distance = pointPolygonTest(contours[maxNum], Point2f(static_cast<float>(p.x), static_cast<float>(p.y)), true);
			if (j == 0 && distance >= 0)
			{
				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
				Myresult += QString::fromStdString(Tblock.text);

			}
			contour.push_back(p);
		}

		contours1.push_back(contour);
	}
	qDebug() << "Myresult:" << Myresult;
	cv::polylines(OrigenImage, contours1, true, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
}



//备选81式步枪
//void CAlgoCodeReview::RifleModel81()
//{
//
//	Mat element = getStructuringElement(MORPH_RECT, Size(50, 2));//自定义核
//	Mat ROIImage;
//
//	//cvtColor(maskImage, maskImage, COLOR_BGR2GRAY); //Convert to gray
//	cv::morphologyEx(maskImage, ROIImage, MORPH_DILATE, element, cv::Point(-1, -1), 2);//膨胀处理
//	threshold(ROIImage, ROIImage, 127, 255, THRESH_BINARY);
//
//	namedWindow("原图", 0);
//	resizeWindow("原图", 640, 480);
//	imshow("原图", maskImage);
//
//	namedWindow("形态学处理结果图", 0);
//	resizeWindow("形态学处理结果图", 640, 480);
//	imshow("形态学处理结果图", ROIImage);
//
//	vector<vector<cv::Point >> contours; // Vector for storing contours
//	findContours(ROIImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE, cv::Point()); // 查找轮廓，对应连通域  
//
//	//查找最小轮廓
//	auto least_contour_index = min_element(contours.begin(), contours.end(), [](vector<cv::Point> c1, vector<cv::Point> c2) {return contourArea(c1) < contourArea(c2); }) - contours.begin();
//
//	ROIImage.setTo(0);
//	drawContours(ROIImage, contours, least_contour_index, Scalar(255), -1); // Draw the largest contour using previously stored index.
//
//	namedWindow("筛选图", 0);
//	resizeWindow("筛选图", 640, 480);
//	imshow("筛选图", ROIImage);
//	waitKey(1);
//
//	vector<vector<cv::Point >> contours1;
//	for (int i = 0; i < rsp.blocks.size(); ++i)
//	{
//		std::vector<cv::Point > contour;//数据为[0,0],定义浮点型向量，如[1,2]
//		TextBlock Tblock = rsp.blocks.at(i);//第i个字符包围盒
//
//		for (int j = 0; j < Tblock.polygon.size(); ++j)//包含字符包围盒的顶点坐标的链表，按顺时针顺序排列，第一个顶点是包围盒的左上角,所以Tblock.polygon.size()=4
//		{
//			Coordinate coord = Tblock.polygon.at(j); //coord  二维平面左边的一个点 float x, y; 左上角坐标是Tblock.polygon.at(0)
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
//				cv::putText(OrigenImage, Tblock.text, p, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);//在图片上绘制文字
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
