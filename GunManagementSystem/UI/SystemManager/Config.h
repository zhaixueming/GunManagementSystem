#pragma  once
#include "qsettings.h"

//������
const QString CAMERA_SECTION = "Camera";//
const QString CAMERA_NAME1 = "CameraName1";//
const QString CAMERA_NAME2 = "CameraName2";//

//���ݿ�
const QString DATABASE = "Database";
const QString HOSTNAME = "HostName";
const QString DATABASE_NAME = "DatabaseName";
const QString USER_NAME = "UserName";
const QString PASSWORD = "Password";
//
////�������ݿ�
//const QString RULEDATABASE = "Rule_Database";
//const QString RULE_HOSTNAME = "Rule_HostName";
//const QString RULE_DBNAME = "Rule_DBName";
//const QString RULE_USERNAME = "Rule_UserName";
//const QString RULE_PASSWORD = "Rule_Password";

//���ò���
//const QString PARAM = "Parameter"; //  DATA_SECTION
const QString DATA_SECTION = "Data_Section";
//const QString REGEX = "Regex";
//const QString LOT_REGEX = "LotRegex";
//const QString DISTANCE = "Distance";
//const QString QTY_DISTANCE = "QtyDistance";
//const QString MIN_GRAY = "MinGray";
//const QString MAX_GRAY = "MaxGray";
//const QString SERIAL_NAME = "SerialName";
const QString IMAGE_SAVE_PATH = "SavePath";//����·��




//typedef enum
//{
//	BARCODE_NORMAL = 0,   //һά����ͨ
//	BARCODE_POL,       //һά��ƫ��
//	QRCODE_NORMAL,     //��ά����ͨ
//	QRCODE_POL,        //��ά��ƫ��
//	QRCODE_APPEND      //��ά�븲Ĥ
//}e_ProductType;

class CConfig
{
public:
	CConfig(QString IniPath);
	~CConfig();
	bool SectionExists(QString section);
	QStringList GetChildKeys(QString Section);
	int GetInt(QString Section,QString Key);
	double GetDouble(QString Section,QString Key);
	QString GetString(QString Section,QString Key);
	bool GetBool(QString Section,QString Key);
	void Write(QString Section,QString Key,QVariant Value);
	void RemoveKey(QString Section);
private:
	QString m_IniPath;
	QSettings *m_Settings;
};