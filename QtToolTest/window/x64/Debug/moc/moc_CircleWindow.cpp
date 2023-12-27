/****************************************************************************
** Meta object code from reading C++ file 'CircleWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CircleWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CircleWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CircleWindow_t {
    QByteArrayData data[16];
    char stringdata0[360];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CircleWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CircleWindow_t qt_meta_stringdata_CircleWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CircleWindow"
QT_MOC_LITERAL(1, 13, 25), // "on_pBtn_ReadImage_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_pBtn_FitImage_clicked"
QT_MOC_LITERAL(4, 65, 26), // "on_btn_ClearWindow_clicked"
QT_MOC_LITERAL(5, 92, 27), // "on_ckb_ShowObj_stateChanged"
QT_MOC_LITERAL(6, 120, 4), // "arg1"
QT_MOC_LITERAL(7, 125, 19), // "on_btn_Hide_clicked"
QT_MOC_LITERAL(8, 145, 32), // "on_btn_DrawCircle_Circle_clicked"
QT_MOC_LITERAL(9, 178, 34), // "on_btn_DetectCircle_Circle_cl..."
QT_MOC_LITERAL(10, 213, 29), // "on_btn_SaveCircleData_clicked"
QT_MOC_LITERAL(11, 243, 29), // "on_btn_LoadCircleData_clicked"
QT_MOC_LITERAL(12, 273, 30), // "on_btn_ClearRoi_Circle_clicked"
QT_MOC_LITERAL(13, 304, 15), // "slot_FindCircle"
QT_MOC_LITERAL(14, 320, 26), // "ResultParamsStruct_Circle&"
QT_MOC_LITERAL(15, 347, 12) // "resultParams"

    },
    "CircleWindow\0on_pBtn_ReadImage_clicked\0"
    "\0on_pBtn_FitImage_clicked\0"
    "on_btn_ClearWindow_clicked\0"
    "on_ckb_ShowObj_stateChanged\0arg1\0"
    "on_btn_Hide_clicked\0"
    "on_btn_DrawCircle_Circle_clicked\0"
    "on_btn_DetectCircle_Circle_clicked\0"
    "on_btn_SaveCircleData_clicked\0"
    "on_btn_LoadCircleData_clicked\0"
    "on_btn_ClearRoi_Circle_clicked\0"
    "slot_FindCircle\0ResultParamsStruct_Circle&\0"
    "resultParams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CircleWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 14,   15,

       0        // eod
};

void CircleWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CircleWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pBtn_ReadImage_clicked(); break;
        case 1: _t->on_pBtn_FitImage_clicked(); break;
        case 2: _t->on_btn_ClearWindow_clicked(); break;
        case 3: _t->on_ckb_ShowObj_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btn_Hide_clicked(); break;
        case 5: _t->on_btn_DrawCircle_Circle_clicked(); break;
        case 6: _t->on_btn_DetectCircle_Circle_clicked(); break;
        case 7: _t->on_btn_SaveCircleData_clicked(); break;
        case 8: _t->on_btn_LoadCircleData_clicked(); break;
        case 9: _t->on_btn_ClearRoi_Circle_clicked(); break;
        case 10: { int _r = _t->slot_FindCircle((*reinterpret_cast< ResultParamsStruct_Circle(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CircleWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_CircleWindow.data,
    qt_meta_data_CircleWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CircleWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CircleWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CircleWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CircleWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
