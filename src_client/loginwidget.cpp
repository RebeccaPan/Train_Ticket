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
    if(ui->lineEdit_username->text() == "") {Widget::SimpleMessageBox("", "请填写username"); return;}
    if(ui->lineEdit_password->text() == "") {Widget::SimpleMessageBox("", "请填写password"); return;}

    QString loginCmd = "login";
    loginCmd += " -u " + ui->lineEdit_username->text();
    loginCmd += " -p " + ui->lineEdit_password->text();
    Widget::SendMessage(loginCmd);
    QString loginRecv = Widget::RecvMessage();
    if (loginRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (loginRecv == "0\n") {
            Widget::SimpleMessageBox("写好了", "登陆成功");
            hide();
            main_widget->cur_username = ui->lineEdit_username->text();
            main_widget->init();
            main_widget->show();
        }
        else {
            Widget::SimpleMessageBox("写好了", "登陆失败");
        }
    }
}
