#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include "QAction"
#include "QMenu"
#include <QUrl>
#include "QDesktopServices"
#include "QCloseEvent"
#include "QShowEvent"
#include "QMap"
#include "QtWebKit/QtWebKit"
#include "QtNetwork"
#include "QTableWidget"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_tabWidget_currentChanged(int index);
    void closeEvent_re();
    void closeEvent(QCloseEvent *e);
    void showHide(QSystemTrayIcon::ActivationReason);
    void habralink();
    void updater_news();
    void updater_sandbox();
    void updater_qa();
    void readynew(QNetworkReply* resulti);
    void readysandbox(QNetworkReply* resulti);
    void readyqa(QNetworkReply* resulti);
    void updater_db();


private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trIcon;
    int closeid;
    QMap<QString,QString> templatehtml;
    QMap<QString, QMap<QString,QString> > habranews;
    QMap<QString, QMap<QString,QString> > habrapes;
    QMap<QString, QMap<QString,QString> > habraqa;
    int habranews_new;
    int habrapes_new;
    int habraqa_new;
    QNetworkReply *currentReplynews;
    QNetworkAccessManager *managernews;
    QNetworkReply *currentReplypes;
    QNetworkAccessManager *managerpes;
    QNetworkReply *currentReplyqa;
    QNetworkAccessManager *managerqa;
    int parsing;

};

#endif // MAINWINDOW_H
