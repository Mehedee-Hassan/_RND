#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);



private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *tray;
    QMenu *trayIconMenu;
    QAction *restoreAction;
    QAction *onCLickRestoreAction;
    QIcon trayIcon;
    void createTray();
    void changeEvent(QEvent* event);


};


#endif // MAINWINDOW_H
