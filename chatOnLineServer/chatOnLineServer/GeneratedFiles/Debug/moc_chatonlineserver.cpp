/****************************************************************************
** Meta object code from reading C++ file 'chatonlineserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chatonlineserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatonlineserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chatOnLineServer_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatOnLineServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatOnLineServer_t qt_meta_stringdata_chatOnLineServer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "chatOnLineServer"
QT_MOC_LITERAL(1, 17, 13), // "onStartServer"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "onSetPort"
QT_MOC_LITERAL(4, 42, 15), // "onNewConnection"
QT_MOC_LITERAL(5, 58, 21) // "readMessageFromClient"

    },
    "chatOnLineServer\0onStartServer\0\0"
    "onSetPort\0onNewConnection\0"
    "readMessageFromClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatOnLineServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chatOnLineServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chatOnLineServer *_t = static_cast<chatOnLineServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartServer(); break;
        case 1: _t->onSetPort(); break;
        case 2: _t->onNewConnection(); break;
        case 3: _t->readMessageFromClient(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject chatOnLineServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_chatOnLineServer.data,
      qt_meta_data_chatOnLineServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chatOnLineServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatOnLineServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chatOnLineServer.stringdata0))
        return static_cast<void*>(const_cast< chatOnLineServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int chatOnLineServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
