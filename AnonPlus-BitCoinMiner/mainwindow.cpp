#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mt(NULL)
{
    ui->setupUi(this);
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(on_help_about_triggered()));
<<<<<<< HEAD
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_button_start_triggered()));
=======
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
>>>>>>> 5021be8

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


<<<<<<< HEAD
void MainWindow::on_button_start_triggered()
{
    mt =  new MiningThread();
    mt->start();
}

=======
void MainWindow::on_button_clicked()
{
    if(mt == NULL)
        mt  = new JsonRpcCall(this);
    QUrl u(DEF_RPC_URL);
    u.setUserName(DEF_RPC_USERNAME);
    u.setPassword(DEF_RPC_PASSWORD);

    connect(mt,SIGNAL(rcpCallReply(JsonRpcCall*,QVariant)),
            this, SLOT(on_json_rpc_called(JsonRpcCall*,QVariant)));
    mt->rpcCall(u, false, false);
}

void MainWindow::on_json_rpc_called(JsonRpcCall*, QVariant v)
{
    qDebug("on_json_rpc_called reached");
    QJson::Serializer serializer;
    qDebug() << serializer.serialize( v);

}
>>>>>>> 5021be8
