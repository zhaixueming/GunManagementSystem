/****************************************************************************
** Meta object code from reading C++ file 'SysMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UI/SysMainWindow/SysMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SysMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SysMainWindow_t {
    QByteArrayData data[13];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysMainWindow_t qt_meta_stringdata_SysMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SysMainWindow"
QT_MOC_LITERAL(1, 14, 20), // "SendStackWidgetIndex"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 15), // "SendSoftTrigger"
QT_MOC_LITERAL(5, 58, 15), // "SendCameraImage"
QT_MOC_LITERAL(6, 74, 3), // "Mat"
QT_MOC_LITERAL(7, 78, 5), // "image"
QT_MOC_LITERAL(8, 84, 18), // "slotAccountManager"
QT_MOC_LITERAL(9, 103, 14), // "slotCodeReview"
QT_MOC_LITERAL(10, 118, 15), // "slotInfoManager"
QT_MOC_LITERAL(11, 134, 18), // "ReceiveCameraImage"
QT_MOC_LITERAL(12, 153, 18) // "ReceiveSoftTrigger"

    },
    "SysMainWindow\0SendStackWidgetIndex\0\0"
    "index\0SendSoftTrigger\0SendCameraImage\0"
    "Mat\0image\0slotAccountManager\0"
    "slotCodeReview\0slotInfoManager\0"
    "ReceiveCameraImage\0ReceiveSoftTrigger"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    2,   68,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    3,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    3,    7,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void SysMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SysMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendStackWidgetIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SendSoftTrigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SendCameraImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 3: _t->slotAccountManager(); break;
        case 4: _t->slotCodeReview(); break;
        case 5: _t->slotInfoManager(); break;
        case 6: _t->ReceiveCameraImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 7: _t->ReceiveSoftTrigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SysMainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysMainWindow::SendStackWidgetIndex)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SysMainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysMainWindow::SendSoftTrigger)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SysMainWindow::*)(int , Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysMainWindow::SendCameraImage)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SysMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SysMainWindow.data,
    qt_meta_data_SysMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SysMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SysMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SysMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SysMainWindow::SendStackWidgetIndex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SysMainWindow::SendSoftTrigger(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SysMainWindow::SendCameraImage(int _t1, Mat _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
