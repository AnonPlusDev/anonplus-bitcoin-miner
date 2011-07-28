#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "miningthread.h"
#include "aboutdialog.h"

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

private slots:
    void on_help_about_triggered();
    void on_button_start_triggered();

};

#endif // MAINWINDOW_H
