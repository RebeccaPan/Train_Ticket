#include "registerfirstuser.h"
#include "ui_registerfirstuser.h"
#include "widget.h"

RegisterFirstUser::RegisterFirstUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterFirstUser) {
    ui->setupUi(this);

    connect(ui->do_register, SIGNAL(clicked()), this, SLOT(do_register()));
}

void RegisterFirstUser::do_register() {
//    Widget::PigeonBox(); // TODO

    if(ui->username_inputbox->text() == "") {
        Widget::SimpleMessageBox("", "请填写username");
        return;
    }
    if(ui->password_inputbox->text() == "") {
        Widget::SimpleMessageBox("", "请填写password");
        return;
    }
    if(ui->name_inputbox->text() == "") {
        Widget::SimpleMessageBox("", "请填写name");
        return;
    }
    if(ui->mail_addr_inputbox->text() == "") {
        Widget::SimpleMessageBox("", "请填写mail_addr");
        return;
    }

    QString registerCmd = "add_user -c NULL";
    registerCmd += " -u " + ui->username_inputbox->text();
    registerCmd += " -p " + ui->password_inputbox->text();
    registerCmd += " -n " + ui->name_inputbox->text();
    registerCmd += " -m " + ui->mail_addr_inputbox->text();
    registerCmd += " -g NULL";
    Widget::SendMessage(registerCmd);
    QString registerRecv = Widget::RecvMessage();
    if (registerRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        while (registerRecv != "over") {
            if (registerRecv == "0") {
                Widget::SimpleMessageBox("实际上还没写呢", "注册成功");
            }
            else {
                Widget::SimpleMessageBox("实际上还没写呢", "注册失败");
            }
            registerRecv = Widget::RecvMessage();
        }
    }
    hide();
}

RegisterFirstUser::~RegisterFirstUser() {
    delete ui;
}
