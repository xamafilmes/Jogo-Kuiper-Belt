/****************************************************************************
** Meta object code from reading C++ file 'Jogar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Jogar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Jogar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSJogarENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSJogarENDCLASS = QtMocHelpers::stringData(
    "Jogar",
    "add_asteroides",
    "",
    "imprimir_vida",
    "criar_itens_para_nave",
    "asteroide_tamanho",
    "retira_texto_item",
    "missil_medio_placar_decrementar",
    "missil_grande_placar_decrementar"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSJogarENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    1,   52,    2, 0x0a,    3 /* Public */,
       6,    0,   55,    2, 0x0a,    5 /* Public */,
       7,    0,   56,    2, 0x0a,    6 /* Public */,
       8,    0,   57,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Jogar::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSJogarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSJogarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSJogarENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Jogar, std::true_type>,
        // method 'add_asteroides'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'imprimir_vida'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'criar_itens_para_nave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'retira_texto_item'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'missil_medio_placar_decrementar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'missil_grande_placar_decrementar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Jogar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Jogar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add_asteroides(); break;
        case 1: _t->imprimir_vida(); break;
        case 2: _t->criar_itens_para_nave((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->retira_texto_item(); break;
        case 4: _t->missil_medio_placar_decrementar(); break;
        case 5: _t->missil_grande_placar_decrementar(); break;
        default: ;
        }
    }
}

const QMetaObject *Jogar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Jogar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSJogarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Jogar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
