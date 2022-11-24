#pragma once
#include "ui_SystemManager.h"
#include "AdminLogin.h"
#include "AdminWithEphorLogin.h"
#include "DatabaseOperator.h"
#include "QStandardItemModel"
#include "ActiveQt/QAxObject"
#include "opencv2/opencv.hpp"
#include "AlgoOCR_CodeReview.h"
#include "PrintAPI.h"
#include "QtTextToSpeech/QTextToSpeech"
#include "qmutex.h"

using namespace std;
using namespace cv;

typedef struct
{
	int type;  //1 箱装  2 单装
	int index;  //数据库表-BoxPackedDetailsTable-序号
	QString PackedNum;//数据库表-BoxPackedDetailsTable-装箱单号
	QString BFWenJianHao; //数据库表-SinglePackedTable-退役报废文件号
	QString DBPingZhengHao;//数据库表-SinglePackedTable-调拨凭证号
	QString ZBDaiMa;//数据库表-SinglePackedTable-装备代码
	QString SerialNumber;//数据库表-BoxPackedDetailsTable-索引

	void clear()
	{
		type = 0;
		index = -1;
		PackedNum.clear();
		BFWenJianHao.clear();
		DBPingZhengHao.clear();
		ZBDaiMa.clear();
		SerialNumber.clear();

	}
}s_CurrentMessage;

class CSystemMangaer :public QDialog
{
	Q_OBJECT
public:
	CSystemMangaer(QDialog *parent = NULL);


	~CSystemMangaer();
private:
	void InitVariables();
	void InitConnections();
	bool CheckRepeat(QString &errMsg);

private:
	Ui::SystemManager ui;
	bool m_bInitAlogSuccess;
	s_CurrentMessage m_curMsg;//当前信息
	QString m_CurDZBianHao;   //识别的单装编号
	QString m_QSQingKuang;    //缺失情况
	QList<QString> m_Password;
	//QStandardItemModel *m_ListViewModel;
	//切换到拍照tab之前的状态
	//1：箱装信息列表
	//2：单装信息
	int m_PreviousIndex;

	e_GunModel CurGunModelflag;

	Mat CodeImage;
	Mat GunImage;
	//Mat DetectImage;
	QMutex m_Mutex;

	//void Remainder();
	void ExportGridA9();

	//bool saveImage1 = false;
	//bool saveImage2=false;


private slots:
	//主界面三个入口链接相应窗口
	void ReceiveStackWidgetIndex(int index);
	//添加用户
	void AddUser();
	//查询用户
	void QueryUserInfo();
	//编辑用户
	void ModifyUser();
	//删除用户
	void DeleteUser();

	//添加箱装信息
	void AddBoxPacked();
	//查询箱装信息
	void QueryBoxPacked();
	//编辑箱装信息
	void ModifyBoxPackedInfo();
	//删除箱装信息
	void DeleteBoxPackedInfo();
	//点击装箱单号,进入箱装列表操作
	void slotClickToolButton();
	//箱装列表返回
	void BoxDetailsReturn();
	//编辑箱装列表
	void EditPackedListInfo();
	//删除箱装列表
	void DeletePackedListInfo();
	//打印装箱清单
	void PrintBoxList();

	//新建单装信息
	void AddSinglePacked();
	//编辑单装信息
	void EditSinglePacked();
	//删除单装信息
	void DeleteSinglePacked();
	//查询单装信息
	void QuerySinglePacked();
	//打印单装卡片
	void PrintSinglePacked();

	//查询信息
	void QueryInformations();
	//出库信息查询
	void QueryDeliveryInformations();
	//显示库存
	void Remainder();
	//拍照检视返回按钮
	void ImageGrabberReturn();
	//导出excel
	void ExportExcel();
	//出库
	void DoDelivery();

	//编码拍照
	void SoftTriggerCodeCamera();
	//整抢拍照
	void SoftTriggerWholeCamera();
	void ReceiveImage(int index, Mat image);
	//保存识别结果，修改数据库中的单装编码
	void SaveRecognizeResult();
	//人工修正识别结果
	void DoCorrection();
	void DoSpeaker();
signals:
	void SendSoftTrigger(int index);
};
