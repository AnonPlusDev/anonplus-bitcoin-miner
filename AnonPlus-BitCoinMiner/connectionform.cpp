#include "connectionform.h"
#include "ui_connectionform.h"

ConnectionForm::ConnectionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionForm)
{
    ui->setupUi(this);
}

ConnectionForm::~ConnectionForm()
{
    delete ui;
}


quint16 ConnectionForm::getPort(void)
{
   bool ok;
   quint16 p;
   p = static_cast<quint16> (ui->field_port->text().toInt(&ok));
   if(ok)
   {
       if(p >= 0 && p <= 65535)
            return p;
       else
            return 8332;
   } else
   {
       return 8332;
   }

}

QString ConnectionForm::getServer(void)
{
    return ui->field_server->text();
}

QString ConnectionForm::getScheme(void)
{
    return ui->combo_scheme->itemText(ui->combo_scheme->currentIndex());
}

QString ConnectionForm::getUser(void)
{
    return ui->field_user->text();
}

QString ConnectionForm::getpass(void)
{
    return ui->field_pass->text();
}
