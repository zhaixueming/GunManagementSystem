#pragma once

#include <QObject>
#include<QMap>
#include "VimoOCRModule.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace smartmore;

typedef enum
{
	DEFAULT_MODEL,
	RIFLE_MODEL95,
	RIFLE_MODEL951,
	PISTOL_MODEL54,
	RIFLE_MODEL81,
	PISTOL_MODEL92
}e_GunModel;

typedef QMap<e_GunModel, VimoOCRModule*> MapGunModle_OCRModule;

class CAlgoCodeReview:public QObject
{
	Q_OBJECT
public:
	static CAlgoCodeReview *GetInstance();
	~CAlgoCodeReview();
	void SetGunModel(e_GunModel GunModel);
	bool InitAlgo();
	bool RunAlog(Mat &image,QString &result);

	//bool SetGunModel(e_GunModel type);//枪只模型
private:
	CAlgoCodeReview(QObject *parent = NULL);
	class GarbageCollection
	{
	public:
		~GarbageCollection()
		{
			if (CAlgoCodeReview::m_Instance)
			{
				delete CAlgoCodeReview::m_Instance;
				CAlgoCodeReview::m_Instance = NULL;
			}
		}
	};

private:
	//不同模型后处理
	void DefaultModel();
	void RifleModel95();
	void RifleModel951();
	void PistolModel54();
	void PistolModel92();
	void RifleModel81();

private:
	static CAlgoCodeReview *m_Instance;
	static GarbageCollection m_Collection;
	bool m_bInitSuccess;

	MapGunModle_OCRModule m_OcrModules;
	//VimoOCRModule m_OcrModule;
	e_GunModel m_CurModel;//模型

	OCRResponse rsp;
	Mat OrigenImage;
	Coordinate coord0;

	Mat maskImage;
	QString Myresult;
	

};
