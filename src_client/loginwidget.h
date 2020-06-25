#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

#include "mainwidget.h"
#include "registerfirstuser.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void register_first_user();
    void login();

    void on_lineEdit_password_textEdited(const QString &arg1);

private:
    Ui::LoginWidget *ui;
    MainWidget *main_widget;
    RegisterFirstUser *register_first_user_widget;
};

#endif // LOGINWIDGET_H
