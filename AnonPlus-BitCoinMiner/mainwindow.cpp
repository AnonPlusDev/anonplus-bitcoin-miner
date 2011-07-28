#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(on_help_about_triggered()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_button_start_triggered()));

}

MainWindow::~MainWindow()
{
    delete mt;
    delete ui;
}

void MainWindow::on_help_about_triggered()
{
    aboutDialog = new AboutDialog(this);
    aboutDialog->setAttribute(Qt::WA_DeleteOnClose, true);
    aboutDialog->show();
}


void MainWindow::on_button_start_triggered()
{
    mt =  new MiningThread();
    mt->start();
}

