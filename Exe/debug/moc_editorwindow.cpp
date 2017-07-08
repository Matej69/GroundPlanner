/****************************************************************************
** Meta object code from reading C++ file 'editorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/WindowForms/editorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditorWindow_t {
    QByteArrayData data[10];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditorWindow_t qt_meta_stringdata_EditorWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EditorWindow"
QT_MOC_LITERAL(1, 13, 18), // "on_roomAdd_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "on_pointAdd_clicked"
QT_MOC_LITERAL(4, 53, 19), // "on_floorAdd_clicked"
QT_MOC_LITERAL(5, 73, 21), // "on_roomDelete_clicked"
QT_MOC_LITERAL(6, 95, 22), // "on_pointDelete_clicked"
QT_MOC_LITERAL(7, 118, 22), // "on_floorDelete_clicked"
QT_MOC_LITERAL(8, 141, 27), // "on_dropBox_floors_activated"
QT_MOC_LITERAL(9, 169, 5) // "_name"

    },
    "EditorWindow\0on_roomAdd_clicked\0\0"
    "on_pointAdd_clicked\0on_floorAdd_clicked\0"
    "on_roomDelete_clicked\0on_pointDelete_clicked\0"
    "on_floorDelete_clicked\0"
    "on_dropBox_floors_activated\0_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditorWindow[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void EditorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditorWindow *_t = static_cast<EditorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_roomAdd_clicked(); break;
        case 1: _t->on_pointAdd_clicked(); break;
        case 2: _t->on_floorAdd_clicked(); break;
        case 3: _t->on_roomDelete_clicked(); break;
        case 4: _t->on_pointDelete_clicked(); break;
        case 5: _t->on_floorDelete_clicked(); break;
        case 6: _t->on_dropBox_floors_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EditorWindow::staticMetaObject = {
    { &AUserWindow::staticMetaObject, qt_meta_stringdata_EditorWindow.data,
      qt_meta_data_EditorWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditorWindow.stringdata0))
        return static_cast<void*>(const_cast< EditorWindow*>(this));
    return AUserWindow::qt_metacast(_clname);
}

int EditorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AUserWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
