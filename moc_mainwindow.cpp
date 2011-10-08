/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Oct 8 12:48:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      69,   67,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     204,  196,   11,   11, 0x08,
     229,  196,   11,   11, 0x08,
     258,  196,   11,   11, 0x08,
     282,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0index\0on_tabWidget_currentChanged(int)\0"
    "closeEvent_re()\0e\0closeEvent(QCloseEvent*)\0"
    "showHide(QSystemTrayIcon::ActivationReason)\0"
    "habralink()\0updater_news()\0updater_sandbox()\0"
    "updater_qa()\0resulti\0readynew(QNetworkReply*)\0"
    "readysandbox(QNetworkReply*)\0"
    "readyqa(QNetworkReply*)\0updater_db()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: closeEvent_re(); break;
        case 2: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: showHide((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 4: habralink(); break;
        case 5: updater_news(); break;
        case 6: updater_sandbox(); break;
        case 7: updater_qa(); break;
        case 8: readynew((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: readysandbox((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: readyqa((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: updater_db(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
