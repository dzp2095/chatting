/****************************************************************************
** Meta object code from reading C++ file 'chatonline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chatonline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatonline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chatOnLine_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatOnLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatOnLine_t qt_meta_stringdata_chatOnLine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "chatOnLine"
QT_MOC_LITERAL(1, 11, 13), // "finishConnect"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "success"
QT_MOC_LITERAL(4, 34, 3), // "msg"
QT_MOC_LITERAL(5, 38, 20), // "readMessgeFromServer"
QT_MOC_LITERAL(6, 59, 19), // "checkLoginIsSuccess"
QT_MOC_LITERAL(7, 79, 6), // "logout"
QT_MOC_LITERAL(8, 86, 9), // "onOpenDlg"
QT_MOC_LITERAL(9, 96, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(10, 113, 4), // "item"
QT_MOC_LITERAL(11, 118, 26), // "sendPrivateMessageToServer"
QT_MOC_LITERAL(12, 145, 2), // "id"
QT_MOC_LITERAL(13, 148, 13) // "chatDlgClosed"

    },
    "chatOnLine\0finishConnect\0\0success\0msg\0"
    "readMessgeFromServer\0checkLoginIsSuccess\0"
    "logout\0onOpenDlg\0QTreeWidgetItem*\0"
    "item\0sendPrivateMessageToServer\0id\0"
    "chatDlgClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatOnLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    2,   57,    2, 0x08 /* Private */,
      11,    2,   62,    2, 0x08 /* Private */,
      13,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void chatOnLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chatOnLine *_t = static_cast<chatOnLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finishConnect((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->readMessgeFromServer(); break;
        case 2: _t->checkLoginIsSuccess(); break;
        case 3: _t->logout(); break;
        case 4: _t->onOpenDlg((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->sendPrivateMessageToServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 6: _t->chatDlgClosed((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject chatOnLine::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_chatOnLine.data,
      qt_meta_data_chatOnLine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chatOnLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatOnLine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chatOnLine.stringdata0))
        return static_cast<void*>(const_cast< chatOnLine*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int chatOnLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
