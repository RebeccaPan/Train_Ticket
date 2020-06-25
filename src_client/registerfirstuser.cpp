#include "registerfirstuser.h"
#include "ui_registerfirstuser.h"
#include "widget.h"

RegisterFirstUser::RegisterFirstUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterFirstUser) {
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/Main"));

    connect(ui->do_register, SIGNAL(clicked()), this, SLOT(do_register()));
}

void RegisterFirstUser::do_register() {
    if(ui->username_inputbox->text() == "")  {Widget::SimpleMessageBox("", "请填写username"); return;}
    if(ui->password_inputbox->text() == "")  {Widget::SimpleMessageBox("", "请填写password"); return;}
    if(ui->name_inputbox->text() == "")      {Widget::SimpleMessageBox("", "请填写name"); return;}
    if(ui->mail_addr_inputbox->text() == "") {Widget::SimpleMessageBox("", "请填写mail_addr"); return;}

    QString registerCmd = "add_user -c ignoredVal";
    registerCmd += " -u " + ui->username_inputbox->text();
    registerCmd += " -p " + ui->password_inputbox->text();
    registerCmd += " -n " + ui->name_inputbox->text();
    registerCmd += " -m " + ui->mail_addr_inputbox->text();
    registerCmd += " -g 10";

    Widget::SendMessage(registerCmd);
    QString registerRecv = Widget::RecvMessage();
    if (registerRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (registerRecv == "0\n") {
            Widget::SimpleMessageBox("写好了", "注册成功");
            hide();
        }
        else Widget::SimpleMessageBox("写好了", "注册失败");
    }
}

RegisterFirstUser::~RegisterFirstUser() {
    delete ui;
}
