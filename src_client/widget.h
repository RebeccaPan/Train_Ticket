#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>

#include "loginwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void connect_server();

public:
    static void SimpleMessageBox( const QString &title, const QString &text );
    static void PigeonBox();
    static void SendMessage( const QString &msg );
    static QString RecvMessage(); // "over" if over

private:
    Ui::Widget *ui;
    static QTcpSocket *socket;
    LoginWidget *login_widget;

    enum{ PORT = 11031 };
};
#endif // WIDGET_H
