/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qq/engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_engine_t {
    QByteArrayData data[11];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_engine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_engine_t qt_meta_stringdata_engine = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 7),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 8),
QT_MOC_LITERAL(4, 25, 10),
QT_MOC_LITERAL(5, 36, 6),
QT_MOC_LITERAL(6, 43, 8),
QT_MOC_LITERAL(7, 52, 10),
QT_MOC_LITERAL(8, 63, 6),
QT_MOC_LITERAL(9, 70, 13),
QT_MOC_LITERAL(10, 84, 15)
    },
    "engine\0doStart\0\0doMoveUp\0doMoveDown\0"
    "doStop\0onMoveUp\0onMoveDown\0onStop\0"
    "MoveUpEmitter\0MoveDownEmitter\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_engine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    0,   60,    2, 0x05,
       4,    0,   61,    2, 0x05,
       5,    0,   62,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    0,   65,    2, 0x0a,
       9,    0,   66,    2, 0x0a,
      10,    0,   67,    2, 0x0a,

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
    QMetaType::Void,

       0        // eod
};

void engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        engine *_t = static_cast<engine *>(_o);
        switch (_id) {
        case 0: _t->doStart(); break;
        case 1: _t->doMoveUp(); break;
        case 2: _t->doMoveDown(); break;
        case 3: _t->doStop(); break;
        case 4: _t->onMoveUp(); break;
        case 5: _t->onMoveDown(); break;
        case 6: _t->onStop(); break;
        case 7: _t->MoveUpEmitter(); break;
        case 8: _t->MoveDownEmitter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::doStart)) {
                *result = 0;
            }
        }
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::doMoveUp)) {
                *result = 1;
            }
        }
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::doMoveDown)) {
                *result = 2;
            }
        }
        {
            typedef void (engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&engine::doStop)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject engine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_engine.data,
      qt_meta_data_engine,  qt_static_metacall, 0, 0}
};


const QMetaObject *engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *engine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_engine.stringdata))
        return static_cast<void*>(const_cast< engine*>(this));
    return QObject::qt_metacast(_clname);
}

int engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void engine::doStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void engine::doMoveUp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void engine::doMoveDown()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void engine::doStop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
