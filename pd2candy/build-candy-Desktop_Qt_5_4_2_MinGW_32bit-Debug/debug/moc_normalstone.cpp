/****************************************************************************
** Meta object code from reading C++ file 'normalstone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../candy/normalstone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'normalstone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_normalstone_t {
    QByteArrayData data[5];
    char stringdata[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_normalstone_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_normalstone_t qt_meta_stringdata_normalstone = {
    {
QT_MOC_LITERAL(0, 0, 11), // "normalstone"
QT_MOC_LITERAL(1, 12, 5), // "click"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "slo"
QT_MOC_LITERAL(4, 23, 5) // "check"

    },
    "normalstone\0click\0\0slo\0check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_normalstone[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       3,    3,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void normalstone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        normalstone *_t = static_cast<normalstone *>(_o);
        switch (_id) {
        case 0: _t->click((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->check((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (normalstone::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&normalstone::click)) {
                *result = 0;
            }
        }
        {
            typedef void (normalstone::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&normalstone::slo)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject normalstone::staticMetaObject = {
    { &stone::staticMetaObject, qt_meta_stringdata_normalstone.data,
      qt_meta_data_normalstone,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *normalstone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *normalstone::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_normalstone.stringdata))
        return static_cast<void*>(const_cast< normalstone*>(this));
    return stone::qt_metacast(_clname);
}

int normalstone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = stone::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void normalstone::click(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void normalstone::slo(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
