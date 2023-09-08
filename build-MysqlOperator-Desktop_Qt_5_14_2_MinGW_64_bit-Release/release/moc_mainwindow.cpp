/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../learn/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "connected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "QSqlDatabase"
QT_MOC_LITERAL(4, 35, 2), // "DB"
QT_MOC_LITERAL(5, 38, 8), // "refreash"
QT_MOC_LITERAL(6, 47, 8), // "add_data"
QT_MOC_LITERAL(7, 56, 19), // "inputPrimaryKeyData"
QT_MOC_LITERAL(8, 76, 14), // "PrimaryKeyName"
QT_MOC_LITERAL(9, 91, 10), // "inputValue"
QT_MOC_LITERAL(10, 102, 16), // "QVector<QString>"
QT_MOC_LITERAL(11, 119, 13), // "primerKeyName"
QT_MOC_LITERAL(12, 133, 14), // "primerKeyInput"
QT_MOC_LITERAL(13, 148, 10), // "DeleteData"
QT_MOC_LITERAL(14, 159, 10), // "ChangeData"
QT_MOC_LITERAL(15, 170, 24), // "CatchTableViewMouseClick"
QT_MOC_LITERAL(16, 195, 19), // "CatchTableViewEnter"
QT_MOC_LITERAL(17, 215, 9), // "QureyData"
QT_MOC_LITERAL(18, 225, 11) // "SelectTable"

    },
    "MainWindow\0connected\0\0QSqlDatabase\0"
    "DB\0refreash\0add_data\0inputPrimaryKeyData\0"
    "PrimaryKeyName\0inputValue\0QVector<QString>\0"
    "primerKeyName\0primerKeyInput\0DeleteData\0"
    "ChangeData\0CatchTableViewMouseClick\0"
    "CatchTableViewEnter\0QureyData\0SelectTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   69,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    2,   77,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,
      17,    0,   86,    2, 0x08 /* Private */,
      18,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    8,
    0x80000000 | 10, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected((*reinterpret_cast< QSqlDatabase(*)>(_a[1]))); break;
        case 1: _t->refreash(); break;
        case 2: _t->add_data(); break;
        case 3: { QString _r = _t->inputPrimaryKeyData((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVector<QString> _r = _t->inputValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<QString>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->DeleteData(); break;
        case 6: _t->ChangeData(); break;
        case 7: _t->CatchTableViewMouseClick(); break;
        case 8: _t->CatchTableViewEnter(); break;
        case 9: _t->QureyData(); break;
        case 10: _t->SelectTable(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
