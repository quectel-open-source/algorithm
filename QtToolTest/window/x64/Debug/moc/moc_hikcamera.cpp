/****************************************************************************
** Meta object code from reading C++ file 'hikcamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../hikcamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hikcamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hikcamera_t {
    QByteArrayData data[9];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hikcamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hikcamera_t qt_meta_stringdata_hikcamera = {
    {
QT_MOC_LITERAL(0, 0, 9), // "hikcamera"
QT_MOC_LITERAL(1, 10, 9), // "sendimage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "HObject"
QT_MOC_LITERAL(4, 29, 10), // "initcamera"
QT_MOC_LITERAL(5, 40, 1), // "t"
QT_MOC_LITERAL(6, 42, 11), // "sendmessage"
QT_MOC_LITERAL(7, 54, 1), // "y"
QT_MOC_LITERAL(8, 56, 8) // "sendtime"

    },
    "hikcamera\0sendimage\0\0HObject\0initcamera\0"
    "t\0sendmessage\0y\0sendtime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hikcamera[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void hikcamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hikcamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendimage((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 1: _t->initcamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendmessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendtime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hikcamera::*)(HObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hikcamera::sendimage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hikcamera::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hikcamera::initcamera)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hikcamera::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hikcamera::sendmessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (hikcamera::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hikcamera::sendtime)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hikcamera::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_hikcamera.data,
    qt_meta_data_hikcamera,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hikcamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hikcamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hikcamera.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hikcamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void hikcamera::sendimage(HObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hikcamera::initcamera(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void hikcamera::sendmessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void hikcamera::sendtime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
