#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    habranews_new=0;
    habrapes_new=0;
    habraqa_new=0;
    parsing=0;

    templatehtml["top"]=QString::fromUtf8("<html><head><style type=\"text/css\"> DIV.brd { background: #eeeeee; margin-top:5px; margin-bottom:5px; margin-left:5px; margin-right:0px; padding:5px; } </style></head><body>");
    templatehtml["bottom"]=QString::fromUtf8("</body></html>");
    templatehtml["template"]=QString::fromUtf8("<div class=\"brd\">&nbsp;&nbsp;&nbsp;<b>%5</b>. <a href=\"%1\" style=\"text-decoration: none; font-size:11px; color: #000\"><font face=\"Arial\">%2</font></a> (<b style=\"font-size:12px;\">%3</b>) <a href=\"http://habrahabr.ru/users/%4/\" style=\"font-size:9px; color: #000\">%4</a> </div>");
    templatehtml["templatepes"]=QString::fromUtf8("<div class=\"brd\">&nbsp;&nbsp;&nbsp;<b>%3</b>. <a href=\"%1\" style=\"text-decoration: none; font-size:11px; color: #000\"><font face=\"Arial\">%2</font></a></div>");

    trIcon = new QSystemTrayIcon();
    trIcon->setIcon(QIcon(":/img/icon.png"));
    trIcon->show();
    setWindowTitle(QObject::trUtf8("Habra-Tray"));
    setWindowIcon(QIcon(":/img/icon.png"));

    QMenu *Menu = new QMenu(this);
    QAction *quitAction1 = new QAction("HabraHabr.ru", this);
    connect(quitAction1, SIGNAL(triggered()), this, SLOT(habralink()));
    QAction *quitAction = new QAction("Quit", this);
    connect(quitAction, SIGNAL(triggered()), this, SLOT(closeEvent_re()));
    Menu->addAction(quitAction1);
    Menu->addSeparator();
    Menu->addAction(quitAction);
    trIcon->setContextMenu(Menu);

    this->updater_db();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updater_db()));
    timer->start(60000);

    connect(trIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showHide(QSystemTrayIcon::ActivationReason)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::habralink()
{
    QDesktopServices::openUrl(QUrl("http://habrahabr.ru/", QUrl::TolerantMode));
}

void MainWindow::showHide(QSystemTrayIcon::ActivationReason r) {
    if (r==QSystemTrayIcon::Trigger){
        if (this->isHidden()) {
            this->show();
            trIcon->setIcon(QIcon(":/img/icon.png"));
        } else {
            this->hide();
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *e){
    if(closeid!=2){
        this->hide();
        e->ignore();
    } else {
        e->accept();
    }
}

void MainWindow::closeEvent_re(){
    closeid=2;
    this->close();
}


void MainWindow::updater_db(){
    if(parsing==0){
        parsing=1;
        this->updater_news();
        this->updater_sandbox();
        this->updater_qa();
    }
    parsing=0;
}

void MainWindow::updater_news(){
    managernews = new QNetworkAccessManager(this);
    connect(managernews, SIGNAL(finished(QNetworkReply*)), this, SLOT(readynew(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl("http://habrahabr.ru/blogs/new/"));
    request.setAttribute(QNetworkRequest::CacheSaveControlAttribute, false);
    currentReplynews=managernews->get(request);
}

void MainWindow::updater_sandbox(){
    managerpes = new QNetworkAccessManager(this);
    connect(managerpes, SIGNAL(finished(QNetworkReply*)), this, SLOT(readysandbox(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl("http://habrahabr.ru/sandbox/"));
    request.setAttribute(QNetworkRequest::CacheSaveControlAttribute, false);
    currentReplypes=managerpes->get(request);
}

void MainWindow::updater_qa(){
    managerqa = new QNetworkAccessManager(this);
    connect(managerqa, SIGNAL(finished(QNetworkReply*)), this, SLOT(readyqa(QNetworkReply*)));
    QNetworkRequest request;
    request.setUrl(QUrl("http://habrahabr.ru/qa/"));
    request.setAttribute(QNetworkRequest::CacheSaveControlAttribute, false);
    currentReplyqa=managerqa->get(request);
}

void MainWindow::readynew(QNetworkReply* resulti){
    QString htmltext=templatehtml["top"];
    QString pageall = QString::fromUtf8(resulti->readAll());
    QRegExp rx("<h2 class=\"title\">.+<a href=\"([^\"]*)\" class=\"post_title\">([^<]+)</a>.*<div class=\"author\">\\s*<a title=\"[^\"]*\" href=\"[^\"]*\" >([^<]*)</a>\\s*</div>.*<div class=\"comments\">.*<span class=\"all\">(.*)</span>\\s*</a>\\s*</div>.*<div class=\"clear\"></div>");
    rx.setMinimal(true);
    int pos = 0;
    int y=1;
    while ((pos = rx.indexIn(pageall,pos)) != -1) {
        QString key=rx.cap(1);
        if(!habranews.contains(key)){
            habranews[key]["name"]=rx.cap(2);
            habranews[key]["author"]=rx.cap(3);
            habranews[key]["comment"]=rx.cap(4);
            habranews[key]["url"]=rx.cap(1);
            if(this->isHidden() || ui->tabWidget->currentIndex()!=0){
                habranews_new++;
                ui->tabWidget->setTabText(0,QString::fromUtf8("Хабратопики (%1)").arg(habranews_new));
                if(this->isHidden()){
                    trIcon->setIcon(QIcon(":/img/icon2.png"));
                }
            }
        }
        pos += rx.matchedLength();
        htmltext+=QString(templatehtml["template"]).arg(rx.cap(1)).arg(rx.cap(2)).arg(rx.cap(4)).arg(rx.cap(3)).arg(y);
        y++;
    }
    htmltext+=templatehtml["bottom"];
    ui->topichtml->setHtml(htmltext);
    currentReplynews->deleteLater();
    managernews->deleteLater();
}


void MainWindow::readysandbox(QNetworkReply* resulti){
    QString htmltext=templatehtml["top"];
    QString pageall = QString::fromUtf8(resulti->readAll());
    QRegExp rx("<noindex>\\s*<div class=\"hentry\">.*<a href=\"([^\"]*)\" rel=\"bookmark\" class=\"topic\">([^<]*)</a>.*</div>\\s*</noindex>");
    rx.setMinimal(true);
    int pos = 0;
    int y=1;
    while ((pos = rx.indexIn(pageall,pos)) != -1) {
        QString key=rx.cap(1);
        if(!habrapes.contains(key)){
            habrapes[key]["name"]=rx.cap(2);
            habrapes[key]["url"]=rx.cap(1);
            if(this->isHidden() || ui->tabWidget->currentIndex()!=1){
                habrapes_new++;
                ui->tabWidget->setTabText(1,QString::fromUtf8("Песочница (%1)").arg(habrapes_new));
                if(this->isHidden()){
                    trIcon->setIcon(QIcon(":/img/icon2.png"));
                }
            }
        }
        pos += rx.matchedLength();
        htmltext+=QString(templatehtml["templatepes"]).arg(rx.cap(1)).arg(rx.cap(2)).arg(y);
        y++;
    }
    htmltext+=templatehtml["bottom"];
    ui->peshtml->setHtml(htmltext);
    currentReplypes->deleteLater();
    managerpes->deleteLater();
}


void MainWindow::readyqa(QNetworkReply* resulti){
    QString htmltext=templatehtml["top"];
    QString pageall = QString::fromUtf8(resulti->readAll());
    QRegExp rx("<div class=\"hentry question_hentry\">.*<a href=\"([^\"]*)\" class=\"topic\">([^<]*)</a>.*<div class=\"informative\">\\s*<span><a href=\"[^\"]*\">([^<]*)</a></span>\\s*</div>.*class=\"fn nickname url\"><span>([^<]*)</span></a>.*<div class=\"corner bl\"></div><div class=\"corner br\"></div>");
    rx.setMinimal(true);
    int pos = 0;
    int y=1;
    while ((pos = rx.indexIn(pageall,pos)) != -1) {
        QString key=rx.cap(1);
        if(!habraqa.contains(key)){
            habraqa[key]["name"]=rx.cap(2);
            habraqa[key]["url"]=rx.cap(1);
            if(this->isHidden() || ui->tabWidget->currentIndex()!=2){
                habraqa_new++;
                ui->tabWidget->setTabText(1,QString::fromUtf8("QA (%1)").arg(habraqa_new));
                if(this->isHidden()){
                    trIcon->setIcon(QIcon(":/img/icon2.png"));
                }
            }
        }
        pos += rx.matchedLength();
        htmltext+=QString(templatehtml["template"]).arg(rx.cap(1)).arg(rx.cap(2)).arg(rx.cap(3)).arg(rx.cap(4)).arg(y);
        y++;
    }
    htmltext+=templatehtml["bottom"];
    ui->qahtml->setHtml(htmltext);
    currentReplyqa->deleteLater();
    managerqa->deleteLater();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==0){
        ui->tabWidget->setTabText(0,QString::fromUtf8("Хабратопики"));
        habranews_new=0;
    } else if(index==1) {
        ui->tabWidget->setTabText(1,QString::fromUtf8("Песочница"));
        habrapes_new=0;
    } else if(index==2){
        ui->tabWidget->setTabText(2,QString::fromUtf8("QA"));
        habraqa_new=0;
    }
}



