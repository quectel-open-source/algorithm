/****************************************************************************
** Meta object code from reading C++ file 'BarcodeClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../BarcodeClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BarcodeClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BarcodeClass_t {
    QByteArrayData data[18];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BarcodeClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BarcodeClass_t qt_meta_stringdata_BarcodeClass = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BarcodeClass"
QT_MOC_LITERAL(1, 13, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(4, 60, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(5, 84, 15), // "mousePressEvent"
QT_MOC_LITERAL(6, 100, 12), // "QMouseEvent*"
QT_MOC_LITERAL(7, 113, 5), // "event"
QT_MOC_LITERAL(8, 119, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(9, 134, 26), // "on_pushButton_save_clicked"
QT_MOC_LITERAL(10, 161, 39), // "on_cmb_BarCodeImage_currentIn..."
QT_MOC_LITERAL(11, 201, 5), // "index"
QT_MOC_LITERAL(12, 207, 26), // "on_btn_FindBarCode_clicked"
QT_MOC_LITERAL(13, 234, 30), // "on_btn_DrawRoi_BarCode_clicked"
QT_MOC_LITERAL(14, 265, 31), // "on_btn_ClearRoi_BarCode_clicked"
QT_MOC_LITERAL(15, 297, 8), // "getimage"
QT_MOC_LITERAL(16, 306, 7), // "HObject"
QT_MOC_LITERAL(17, 314, 8) // "gettitle"

    },
    "BarcodeClass\0on_toolButton_clicked\0\0"
    "on_toolButton_2_clicked\0on_toolButton_3_clicked\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseMoveEvent\0on_pushButton_save_clicked\0"
    "on_cmb_BarCodeImage_currentIndexChanged\0"
    "index\0on_btn_FindBarCode_clicked\0"
    "on_btn_DrawRoi_BarCode_clicked\0"
    "on_btn_ClearRoi_BarCode_clicked\0"
    "getimage\0HObject\0gettitle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BarcodeClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void BarcodeClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BarcodeClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolButton_clicked(); break;
        case 1: _t->on_toolButton_2_clicked(); break;
        case 2: _t->on_toolButton_3_clicked(); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_save_clicked(); break;
        case 6: _t->on_cmb_BarCodeImage_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btn_FindBarCode_clicked(); break;
        case 8: _t->on_btn_DrawRoi_BarCode_clicked(); break;
        case 9: _t->on_btn_ClearRoi_BarCode_clicked(); break;
        case 10: _t->getimage((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 11: _t->gettitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BarcodeClass::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_BarcodeClass.data,
    qt_meta_data_BarcodeClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BarcodeClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BarcodeClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BarcodeClass.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BarcodeClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
