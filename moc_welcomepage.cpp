/****************************************************************************
** Meta object code from reading C++ file 'welcomepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "welcomepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WelcomePage_t {
    QByteArrayData data[18];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WelcomePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WelcomePage_t qt_meta_stringdata_WelcomePage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WelcomePage"
QT_MOC_LITERAL(1, 12, 23), // "on_bgm_vol_valueChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "value"
QT_MOC_LITERAL(4, 43, 26), // "on_settings_button_clicked"
QT_MOC_LITERAL(5, 70, 21), // "on_enter_game_clicked"
QT_MOC_LITERAL(6, 92, 15), // "on_help_clicked"
QT_MOC_LITERAL(7, 108, 20), // "on_next_page_clicked"
QT_MOC_LITERAL(8, 129, 24), // "on_back_to_main2_clicked"
QT_MOC_LITERAL(9, 154, 24), // "on_previous_page_clicked"
QT_MOC_LITERAL(10, 179, 23), // "on_back_to_main_clicked"
QT_MOC_LITERAL(11, 203, 21), // "on_start_game_clicked"
QT_MOC_LITERAL(12, 225, 25), // "on_practicebutton_clicked"
QT_MOC_LITERAL(13, 251, 23), // "on_doublebutton_clicked"
QT_MOC_LITERAL(14, 275, 27), // "on_effects_vol_valueChanged"
QT_MOC_LITERAL(15, 303, 21), // "on_backbutton_clicked"
QT_MOC_LITERAL(16, 325, 17), // "change_bgm_volume"
QT_MOC_LITERAL(17, 343, 21) // "change_effects_volume"

    },
    "WelcomePage\0on_bgm_vol_valueChanged\0"
    "\0value\0on_settings_button_clicked\0"
    "on_enter_game_clicked\0on_help_clicked\0"
    "on_next_page_clicked\0on_back_to_main2_clicked\0"
    "on_previous_page_clicked\0"
    "on_back_to_main_clicked\0on_start_game_clicked\0"
    "on_practicebutton_clicked\0"
    "on_doublebutton_clicked\0"
    "on_effects_vol_valueChanged\0"
    "on_backbutton_clicked\0change_bgm_volume\0"
    "change_effects_volume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WelcomePage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       4,    0,   92,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    1,  102,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,
      16,    1,  106,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void WelcomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WelcomePage *_t = static_cast<WelcomePage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_bgm_vol_valueChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->on_settings_button_clicked(); break;
        case 2: _t->on_enter_game_clicked(); break;
        case 3: _t->on_help_clicked(); break;
        case 4: _t->on_next_page_clicked(); break;
        case 5: _t->on_back_to_main2_clicked(); break;
        case 6: _t->on_previous_page_clicked(); break;
        case 7: _t->on_back_to_main_clicked(); break;
        case 8: _t->on_start_game_clicked(); break;
        case 9: _t->on_practicebutton_clicked(); break;
        case 10: _t->on_doublebutton_clicked(); break;
        case 11: _t->on_effects_vol_valueChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 12: _t->on_backbutton_clicked(); break;
        case 13: _t->change_bgm_volume((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 14: _t->change_effects_volume((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WelcomePage::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_WelcomePage.data,
    qt_meta_data_WelcomePage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WelcomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WelcomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomePage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WelcomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
