#pragma once

#include <QObject>
#include "VimoOCRModule.h"
#include "opencv-4.2.0/include/opencv2/opencv.hpp"
using namespace cv;
using namespace smartmore;

typedef enum
{
	DEFAULT_MODEL,
	RIFLE_MODEL95,
	RIFLE_MODEL951,
	PISTOL_MODEL54
}e_GunModel;


class CAlgoCodeReview:public QObject
{
	Q_OBJECT
public:
	static CAlgoCodeReview *GetInstance();
	~CAlgoCodeReview();
	bool InitAlgo();
	bool RunAlog(Mat &image,QString &result);

	bool SetGunModel(e_GunModel type);//Ç¹Ö»Ä£ÐÍ
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
	static CAlgoCodeReview *m_Instance;
	static GarbageCollection m_Collection;
	bool m_bInitSuccess;
	VimoOCRModule m_OcrModule;

	e_GunModel m_GunModel;
};
