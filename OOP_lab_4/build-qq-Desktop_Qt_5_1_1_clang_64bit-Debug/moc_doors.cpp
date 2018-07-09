/****************************************************************************
** Meta object code from reading C++ file 'doors.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qq/doors.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doors.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_doors_t {
    QByteArrayData data[10];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_doors_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_doors_t qt_meta_stringdata_doors = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 9),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 8),
QT_MOC_LITERAL(4, 26, 9),
QT_MOC_LITERAL(5, 36, 8),
QT_MOC_LITERAL(6, 45, 9),
QT_MOC_LITERAL(7, 55, 8),
QT_MOC_LITERAL(8, 64, 9),
QT_MOC_LITERAL(9, 74, 8)
    },
    "doors\0doOpening\0\0doOpened\0doClosing\0"
    "doClosed\0onOpening\0onOpened\0onClosing\0"
    "onClosed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_doors[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x05,
       3,    0,   55,    2, 0x05,
       4,    0,   56,    2, 0x05,
       5,    0,   57,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x0a,
       7,    0,   59,    2, 0x0a,
       8,    0,   60,    2, 0x0a,
       9,    0,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void doors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        doors *_t = static_cast<doors *>(_o);
        switch (_id) {
        case 0: _t->doOpening(); break;
        case 1: _t->doOpened(); break;
        case 2: _t->doClosing(); break;
        case 3: _t->doClosed(); break;
        case 4: _t->onOpening(); break;
        case 5: _t->onOpened(); break;
        case 6: _t->onClosing(); break;
        case 7: _t->onClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::doOpening)) {
                *result = 0;
            }
        }
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::doOpened)) {
                *result = 1;
            }
        }
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::doClosing)) {
                *result = 2;
            }
        }
        {
            typedef void (doors::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&doors::doClosed)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject doors::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_doors.data,
      qt_meta_data_doors,  qt_static_metacall, 0, 0}
};


const QMetaObject *doors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *doors::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_doors.stringdata))
        return static_cast<void*>(const_cast< doors*>(this));
    return QObject::qt_metacast(_clname);
}

int doors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void doors::doOpening()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void doors::doOpened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void doors::doClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void doors::doClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
