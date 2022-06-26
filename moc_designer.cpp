/****************************************************************************
** Meta object code from reading C++ file 'designer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "designer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'designer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GateDesigner_t {
    QByteArrayData data[21];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GateDesigner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GateDesigner_t qt_meta_stringdata_GateDesigner = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GateDesigner"
QT_MOC_LITERAL(1, 13, 10), // "addAndGate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "addOrGate"
QT_MOC_LITERAL(4, 35, 9), // "calculate"
QT_MOC_LITERAL(5, 45, 18), // "getCurrentSelected"
QT_MOC_LITERAL(6, 64, 13), // "update_values"
QT_MOC_LITERAL(7, 78, 10), // "addNotGate"
QT_MOC_LITERAL(8, 89, 9), // "newWindow"
QT_MOC_LITERAL(9, 99, 13), // "updateDisplay"
QT_MOC_LITERAL(10, 113, 11), // "changePlace"
QT_MOC_LITERAL(11, 125, 11), // "std::string"
QT_MOC_LITERAL(12, 137, 9), // "direction"
QT_MOC_LITERAL(13, 147, 9), // "debugSend"
QT_MOC_LITERAL(14, 157, 7), // "message"
QT_MOC_LITERAL(15, 165, 8), // "checkAnd"
QT_MOC_LITERAL(16, 174, 3), // "one"
QT_MOC_LITERAL(17, 178, 3), // "two"
QT_MOC_LITERAL(18, 182, 7), // "checkOr"
QT_MOC_LITERAL(19, 190, 8), // "checkNot"
QT_MOC_LITERAL(20, 199, 3) // "bit"

    },
    "GateDesigner\0addAndGate\0\0addOrGate\0"
    "calculate\0getCurrentSelected\0update_values\0"
    "addNotGate\0newWindow\0updateDisplay\0"
    "changePlace\0std::string\0direction\0"
    "debugSend\0message\0checkAnd\0one\0two\0"
    "checkOr\0checkNot\0bit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GateDesigner[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      15,    2,   93,    2, 0x08 /* Private */,
      18,    2,   98,    2, 0x08 /* Private */,
      19,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   14,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Int, QMetaType::Int,   20,

       0        // eod
};

void GateDesigner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GateDesigner *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addAndGate(); break;
        case 1: _t->addOrGate(); break;
        case 2: _t->calculate(); break;
        case 3: _t->getCurrentSelected(); break;
        case 4: _t->update_values(); break;
        case 5: _t->addNotGate(); break;
        case 6: _t->newWindow(); break;
        case 7: _t->updateDisplay(); break;
        case 8: _t->changePlace((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->debugSend((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: { int _r = _t->checkAnd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->checkOr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->checkNot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GateDesigner::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GateDesigner.data,
    qt_meta_data_GateDesigner,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GateDesigner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GateDesigner::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GateDesigner.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GateDesigner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
