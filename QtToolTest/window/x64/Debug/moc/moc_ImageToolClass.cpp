/****************************************************************************
** Meta object code from reading C++ file 'ImageToolClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ImageToolClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageToolClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageToolClass_t {
    QByteArrayData data[21];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageToolClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageToolClass_t qt_meta_stringdata_ImageToolClass = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ImageToolClass"
QT_MOC_LITERAL(1, 15, 9), // "sendimage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "HObject"
QT_MOC_LITERAL(4, 34, 13), // "sendimageList"
QT_MOC_LITERAL(5, 48, 13), // "QFileInfoList"
QT_MOC_LITERAL(6, 62, 21), // "on_toolButton_clicked"
QT_MOC_LITERAL(7, 84, 23), // "on_toolButton_2_clicked"
QT_MOC_LITERAL(8, 108, 23), // "on_toolButton_3_clicked"
QT_MOC_LITERAL(9, 132, 15), // "mousePressEvent"
QT_MOC_LITERAL(10, 148, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 161, 5), // "event"
QT_MOC_LITERAL(12, 167, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(13, 182, 24), // "on_btn_openImage_clicked"
QT_MOC_LITERAL(14, 207, 25), // "on_btn_imagefiles_clicked"
QT_MOC_LITERAL(15, 233, 26), // "on_btn_deleteImage_clicked"
QT_MOC_LITERAL(16, 260, 30), // "on_toolButton_provious_clicked"
QT_MOC_LITERAL(17, 291, 26), // "on_toolButton_next_clicked"
QT_MOC_LITERAL(18, 318, 16), // "slot_itemClicked"
QT_MOC_LITERAL(19, 335, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(20, 352, 4) // "item"

    },
    "ImageToolClass\0sendimage\0\0HObject\0"
    "sendimageList\0QFileInfoList\0"
    "on_toolButton_clicked\0on_toolButton_2_clicked\0"
    "on_toolButton_3_clicked\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "on_btn_openImage_clicked\0"
    "on_btn_imagefiles_clicked\0"
    "on_btn_deleteImage_clicked\0"
    "on_toolButton_provious_clicked\0"
    "on_toolButton_next_clicked\0slot_itemClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageToolClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    1,   88,    2, 0x08 /* Private */,
      12,    1,   91,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void ImageToolClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageToolClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendimage((*reinterpret_cast< HObject(*)>(_a[1]))); break;
        case 1: _t->sendimageList((*reinterpret_cast< QFileInfoList(*)>(_a[1]))); break;
        case 2: _t->on_toolButton_clicked(); break;
        case 3: _t->on_toolButton_2_clicked(); break;
        case 4: _t->on_toolButton_3_clicked(); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_btn_openImage_clicked(); break;
        case 8: _t->on_btn_imagefiles_clicked(); break;
        case 9: _t->on_btn_deleteImage_clicked(); break;
        case 10: _t->on_toolButton_provious_clicked(); break;
        case 11: _t->on_toolButton_next_clicked(); break;
        case 12: _t->slot_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageToolClass::*)(HObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageToolClass::sendimage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImageToolClass::*)(QFileInfoList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageToolClass::sendimageList)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageToolClass::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ImageToolClass.data,
    qt_meta_data_ImageToolClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageToolClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageToolClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageToolClass.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImageToolClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ImageToolClass::sendimage(HObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageToolClass::sendimageList(QFileInfoList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
