/****************************************************************************
** Meta object code from reading C++ file 'ParameterSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UI/ParameterSetting/ParameterSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ParameterSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CParameterSettings_t {
    QByteArrayData data[18];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CParameterSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CParameterSettings_t qt_meta_stringdata_CParameterSettings = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CParameterSettings"
QT_MOC_LITERAL(1, 19, 15), // "SendCameraImage"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "type"
QT_MOC_LITERAL(4, 41, 3), // "Mat"
QT_MOC_LITERAL(5, 45, 5), // "image"
QT_MOC_LITERAL(6, 51, 15), // "ConnectDatabase"
QT_MOC_LITERAL(7, 67, 17), // "Camera1Controller"
QT_MOC_LITERAL(8, 85, 17), // "Camera2Controller"
QT_MOC_LITERAL(9, 103, 17), // "SwitchCamera1Type"
QT_MOC_LITERAL(10, 121, 5), // "index"
QT_MOC_LITERAL(11, 127, 7), // "checked"
QT_MOC_LITERAL(12, 135, 17), // "SwitchCamera2Type"
QT_MOC_LITERAL(13, 153, 18), // "ReceiveSoftTrigger"
QT_MOC_LITERAL(14, 172, 19), // "ReceiveCamera1Image"
QT_MOC_LITERAL(15, 192, 19), // "ReceiveCamera2Image"
QT_MOC_LITERAL(16, 212, 14), // "BrowseSavePath"
QT_MOC_LITERAL(17, 227, 10) // "SaveConfig"

    },
    "CParameterSettings\0SendCameraImage\0\0"
    "type\0Mat\0image\0ConnectDatabase\0"
    "Camera1Controller\0Camera2Controller\0"
    "SwitchCamera1Type\0index\0checked\0"
    "SwitchCamera2Type\0ReceiveSoftTrigger\0"
    "ReceiveCamera1Image\0ReceiveCamera2Image\0"
    "BrowseSavePath\0SaveConfig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CParameterSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    2,   77,    2, 0x08 /* Private */,
      12,    2,   82,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CParameterSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CParameterSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendCameraImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 1: _t->ConnectDatabase(); break;
        case 2: _t->Camera1Controller(); break;
        case 3: _t->Camera2Controller(); break;
        case 4: _t->SwitchCamera1Type((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->SwitchCamera2Type((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->ReceiveSoftTrigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ReceiveCamera1Image((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 8: _t->ReceiveCamera2Image((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 9: _t->BrowseSavePath(); break;
        case 10: _t->SaveConfig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CParameterSettings::*)(int , Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CParameterSettings::SendCameraImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CParameterSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CParameterSettings.data,
    qt_meta_data_CParameterSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CParameterSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CParameterSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CParameterSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CParameterSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CParameterSettings::SendCameraImage(int _t1, Mat _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
