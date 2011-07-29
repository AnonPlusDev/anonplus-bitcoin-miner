#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <qjson/serializer.h>
#include <QMainWindow>
<<<<<<< HEAD
#include "miningthread.h"
=======

>>>>>>> 5021be8
#include "aboutdialog.h"
#include "jsonrpccall.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MiningThread* mt;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AboutDialog* aboutDialog;
    JsonRpcCall* mt;

private slots:
    void on_help_about_triggered();
<<<<<<< HEAD
    void on_button_start_triggered();
=======
    void on_button_clicked();

    void on_json_rpc_called(JsonRpcCall*, QVariant v);


>>>>>>> 5021be8

};

#endif // MAINWINDOW_H
