#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "widget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);

    main_widget = new MainWidget();
    register_first_user_widget = new RegisterFirstUser();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(register_first_user()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(login()));
}

LoginWidget::~LoginWidget() {
    delete ui;
    delete main_widget;
    delete register_first_user_widget;
}

void LoginWidget::register_first_user() {
    register_first_user_widget->show();
}

void LoginWidget::login() {
//    Widget::PigeonBox(); // TODO

    if(ui->lineEdit_username ->text() == "") {
        Widget::SimpleMessageBox("", "请填写username");
        return;
    }
    if(ui->lineEdit_password ->text() == "") {
        Widget::SimpleMessageBox("", "请填写password");
        return;
    }

    QString loginCmd = "add_user -c NULL";
    loginCmd += " -u " + ui->lineEdit_username->text();
    loginCmd += " -p " + ui->lineEdit_password->text();
    Widget::SendMessage(loginCmd);
    QString loginRecv = Widget::RecvMessage();
    if (loginRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        while (loginRecv != "over") {
            if (loginRecv == "0") {
                Widget::SimpleMessageBox("实际上还没写呢", "登陆成功");
            }
            else {
                Widget::SimpleMessageBox("实际上还没写呢", "登陆失败");
            }
            loginRecv = Widget::RecvMessage();
        }
    }

    hide();
    main_widget->show();
}
