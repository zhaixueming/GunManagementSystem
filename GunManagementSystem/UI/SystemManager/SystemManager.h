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
	int type;  //1 ��װ  2 ��װ
	int index;  //���ݿ��-BoxPackedDetailsTable-���
	QString PackedNum;//���ݿ��-BoxPackedDetailsTable-װ�䵥��
	QString BFWenJianHao; //���ݿ��-SinglePackedTable-���۱����ļ���
	QString DBPingZhengHao;//���ݿ��-SinglePackedTable-����ƾ֤��
	QString ZBDaiMa;//���ݿ��-SinglePackedTable-װ������
	QString SerialNumber;//���ݿ��-BoxPackedDetailsTable-����

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
	s_CurrentMessage m_curMsg;//��ǰ��Ϣ
	QString m_CurDZBianHao;   //ʶ��ĵ�װ���
	QString m_QSQingKuang;    //ȱʧ���
	QList<QString> m_Password;
	//QStandardItemModel *m_ListViewModel;
	//�л�������tab֮ǰ��״̬
	//1����װ��Ϣ�б�
	//2����װ��Ϣ
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
	//�������������������Ӧ����
	void ReceiveStackWidgetIndex(int index);
	//����û�
	void AddUser();
	//��ѯ�û�
	void QueryUserInfo();
	//�༭�û�
	void ModifyUser();
	//ɾ���û�
	void DeleteUser();

	//�����װ��Ϣ
	void AddBoxPacked();
	//��ѯ��װ��Ϣ
	void QueryBoxPacked();
	//�༭��װ��Ϣ
	void ModifyBoxPackedInfo();
	//ɾ����װ��Ϣ
	void DeleteBoxPackedInfo();
	//���װ�䵥��,������װ�б����
	void slotClickToolButton();
	//��װ�б���
	void BoxDetailsReturn();
	//�༭��װ�б�
	void EditPackedListInfo();
	//ɾ����װ�б�
	void DeletePackedListInfo();
	//��ӡװ���嵥
	void PrintBoxList();

	//�½���װ��Ϣ
	void AddSinglePacked();
	//�༭��װ��Ϣ
	void EditSinglePacked();
	//ɾ����װ��Ϣ
	void DeleteSinglePacked();
	//��ѯ��װ��Ϣ
	void QuerySinglePacked();
	//��ӡ��װ��Ƭ
	void PrintSinglePacked();

	//��ѯ��Ϣ
	void QueryInformations();
	//������Ϣ��ѯ
	void QueryDeliveryInformations();
	//��ʾ���
	void Remainder();
	//���ռ��ӷ��ذ�ť
	void ImageGrabberReturn();
	//����excel
	void ExportExcel();
	//����
	void DoDelivery();

	//��������
	void SoftTriggerCodeCamera();
	//��������
	void SoftTriggerWholeCamera();
	void ReceiveImage(int index, Mat image);
	//����ʶ�������޸����ݿ��еĵ�װ����
	void SaveRecognizeResult();
	//�˹�����ʶ����
	void DoCorrection();
	void DoSpeaker();
signals:
	void SendSoftTrigger(int index);
};
