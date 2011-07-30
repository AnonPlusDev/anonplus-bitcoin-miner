#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mt(NULL)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(&conForm);
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(on_help_about_triggered()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));


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

void MainWindow::on_button_clicked()
{
    if(mt == NULL)
        mt  = new JsonRpcCall(this);
    QString urlS("");
    urlS += conForm.getScheme();
    urlS += "://";
    urlS += conForm.getUser();
    urlS += ":";
    urlS += conForm.getpass();
    urlS += "@";
    urlS += conForm.getServer();
    urlS += ":";
    urlS += QString().sprintf("%d", conForm.getPort());
    urlS += "/";


    QUrl u(urlS);
    qDebug() << "Url: " << u.toString();
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
