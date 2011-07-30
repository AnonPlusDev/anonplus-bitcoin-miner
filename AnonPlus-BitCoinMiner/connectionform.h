#ifndef CONNECTIONFORM_H
#define CONNECTIONFORM_H

#include <QWidget>
#include <QtGlobal>

namespace Ui {
    class ConnectionForm;
}

class ConnectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionForm(QWidget *parent = 0);
    ~ConnectionForm();
    quint16 getPort(void);
    QString getServer(void);
    QString getScheme(void);
    QString getUser(void);
    QString getpass(void);



private:
    Ui::ConnectionForm *ui;
};

#endif // CONNECTIONFORM_H
