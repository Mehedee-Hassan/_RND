#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTray();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}

void MainWindow::createTray(){

    //create tray
    tray= new QSystemTrayIcon(this);

    //setup tray icon
    QPixmap icon(":/back3.png");
    trayIcon= QIcon(icon);
    tray->setIcon(trayIcon);
    tray->setToolTip("MousePad");

    //setup restore
    restoreAction = new QAction(QIcon(":/back3.png"), "Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(show()));


    onCLickRestoreAction = new QAction(this);
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason )),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason )));




     //create system tray menu
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    tray->setContextMenu(trayIconMenu);


    tray->setVisible(true);



}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){


    switch (reason) {
        case QSystemTrayIcon::Trigger:



        case QSystemTrayIcon::DoubleClick:

            this->showNormal();

            break;
        case QSystemTrayIcon::MiddleClick:

            break;
        default:
            ;
        }
}



void MainWindow::changeEvent(QEvent* event){


    switch(event->type()){
        case QEvent::WindowStateChange:{

            if(this->windowState() && (Qt::WindowMinimized)){

                hide();

                tray->showMessage("Hi","I'm here",QSystemTrayIcon::Information,30);

                event->ignore();

            }
            else if(this->windowState() && (Qt::WindowMaximized)){


                //event->ignore();
            }

            break;

        }
    default:
        break;


    }

    QMainWindow::changeEvent(event);
}






