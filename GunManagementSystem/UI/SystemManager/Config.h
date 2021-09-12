#pragma  once
#include "qsettings.h"

//相机相关
const QString CAMERA_SECTION = "Camera";//
const QString CAMERA_NAME1 = "CameraName1";//
const QString CAMERA_NAME2 = "CameraName2";//

//数据库
const QString DATABASE = "Database";
const QString HOSTNAME = "HostName";
const QString DATABASE_NAME = "DatabaseName";
const QString USER_NAME = "UserName";
const QString PASSWORD = "Password";
//
////规则数据库
//const QString RULEDATABASE = "Rule_Database";
//const QString RULE_HOSTNAME = "Rule_HostName";
//const QString RULE_DBNAME = "Rule_DBName";
//const QString RULE_USERNAME = "Rule_UserName";
//const QString RULE_PASSWORD = "Rule_Password";

//配置参数
//const QString PARAM = "Parameter"; //  DATA_SECTION
const QString DATA_SECTION = "Data_Section";
//const QString REGEX = "Regex";
//const QString LOT_REGEX = "LotRegex";
//const QString DISTANCE = "Distance";
//const QString QTY_DISTANCE = "QtyDistance";
//const QString MIN_GRAY = "MinGray";
//const QString MAX_GRAY = "MaxGray";
//const QString SERIAL_NAME = "SerialName";
const QString IMAGE_SAVE_PATH = "SavePath";//保存路径




//typedef enum
//{
//	BARCODE_NORMAL = 0,   //一维码普通
//	BARCODE_POL,       //一维码偏光
//	QRCODE_NORMAL,     //二维码普通
//	QRCODE_POL,        //二维码偏光
//	QRCODE_APPEND      //二维码覆膜
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