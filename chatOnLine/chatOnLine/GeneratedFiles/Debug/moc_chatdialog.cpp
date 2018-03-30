/****************************************************************************
** Meta object code from reading C++ file 'chatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chatDialog_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chatDialog_t qt_meta_stringdata_chatDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "chatDialog"
QT_MOC_LITERAL(1, 11, 24), // "sendPrivateMessageSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "msg"
QT_MOC_LITERAL(4, 41, 2), // "id"
QT_MOC_LITERAL(5, 44, 21), // "closeChatDialogSignal"
QT_MOC_LITERAL(6, 66, 10) // "on_btnSend"

    },
    "chatDialog\0sendPrivateMessageSignal\0"
    "\0msg\0id\0closeChatDialogSignal\0on_btnSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void chatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chatDialog *_t = static_cast<chatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPrivateMessageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->closeChatDialogSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->on_btnSend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chatDialog::*_t)(QString , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chatDialog::sendPrivateMessageSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (chatDialog::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chatDialog::closeChatDialogSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject chatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_chatDialog.data,
      qt_meta_data_chatDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *chatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_chatDialog.stringdata0))
        return static_cast<void*>(const_cast< chatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int chatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void chatDialog::sendPrivateMessageSignal(QString _t1, const int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chatDialog::closeChatDialogSignal(const int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
