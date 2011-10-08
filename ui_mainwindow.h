/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 8 11:36:21 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *topic;
    QGridLayout *gridLayout_2;
    QTextBrowser *topichtml;
    QWidget *pes;
    QGridLayout *gridLayout_3;
    QTextBrowser *peshtml;
    QWidget *qa;
    QGridLayout *gridLayout_4;
    QTextBrowser *qahtml;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 470);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        topic = new QWidget();
        topic->setObjectName(QString::fromUtf8("topic"));
        gridLayout_2 = new QGridLayout(topic);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        topichtml = new QTextBrowser(topic);
        topichtml->setObjectName(QString::fromUtf8("topichtml"));
        topichtml->setAutoFormatting(QTextEdit::AutoAll);
        topichtml->setAcceptRichText(true);
        topichtml->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        topichtml->setOpenExternalLinks(true);

        gridLayout_2->addWidget(topichtml, 0, 0, 1, 1);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/topic.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(topic, icon, QString());
        pes = new QWidget();
        pes->setObjectName(QString::fromUtf8("pes"));
        gridLayout_3 = new QGridLayout(pes);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        peshtml = new QTextBrowser(pes);
        peshtml->setObjectName(QString::fromUtf8("peshtml"));
        peshtml->setAutoFormatting(QTextEdit::AutoAll);
        peshtml->setAcceptRichText(true);
        peshtml->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        peshtml->setOpenExternalLinks(true);

        gridLayout_3->addWidget(peshtml, 0, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/pes.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(pes, icon1, QString());
        qa = new QWidget();
        qa->setObjectName(QString::fromUtf8("qa"));
        gridLayout_4 = new QGridLayout(qa);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        qahtml = new QTextBrowser(qa);
        qahtml->setObjectName(QString::fromUtf8("qahtml"));
        qahtml->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        qahtml->setOpenExternalLinks(true);

        gridLayout_4->addWidget(qahtml, 0, 0, 1, 1);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/qa.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(qa, icon2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(topic), QApplication::translate("MainWindow", "\320\245\320\260\320\261\321\200\320\260\321\202\320\276\320\277\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        peshtml->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pes), QApplication::translate("MainWindow", "\320\237\320\265\321\201\320\276\321\207\320\275\320\270\321\206\320\260", 0, QApplication::UnicodeUTF8));
        qahtml->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(qa), QApplication::translate("MainWindow", "QA", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
