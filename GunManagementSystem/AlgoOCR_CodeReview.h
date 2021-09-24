#pragma once

#include <QObject>
#include "VimoOCRModule.h"
#include "opencv-4.2.0/include/opencv2/opencv.hpp"
using namespace cv;
using namespace smartmore;

class CAlgoCodeReview:public QObject
{
	Q_OBJECT
public:
	static CAlgoCodeReview *GetInstance();
	~CAlgoCodeReview();
	bool InitAlgo();
	bool RunAlog(Mat &image,QString &result);
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
};
