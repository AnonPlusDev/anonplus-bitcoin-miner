#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <qjson/serializer.h>
#include <QMainWindow>

#include "aboutdialog.h"
#include "jsonrpccall.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AboutDialog* aboutDialog;
    JsonRpcCall* mt;

private slots:
    void on_help_about_triggered();
    void on_button_clicked();

    void on_json_rpc_called(JsonRpcCall*, QVariant v);



};

#endif // MAINWINDOW_H
