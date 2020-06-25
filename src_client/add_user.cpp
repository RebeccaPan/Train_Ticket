#include "add_user.h"
#include "ui_add_user.h"
#include "widget.h"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser) {
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/Main"));

    connect(ui->do_add_user, SIGNAL(clicked()), this, SLOT(do_add_user()));
}

void AddUser::do_add_user() {
    if(ui->lineEdit_1_u->text() == "") {Widget::SimpleMessageBox("", "请填写username"); return;}
    if(ui->lineEdit_2_p->text() == "") {Widget::SimpleMessageBox("", "请填写password"); return;}
    if(ui->lineEdit_3_n->text() == "") {Widget::SimpleMessageBox("", "请填写name"); return;}
    if(ui->lineEdit_4_m->text() == "") {Widget::SimpleMessageBox("", "请填写mailAddr"); return;}
    if(ui->lineEdit_5_g->text() == "") {Widget::SimpleMessageBox("", "请填写privilege"); return;}

    QString addUserCmd = "add_user -c " + cur_username;
    addUserCmd += " -u " + ui->lineEdit_1_u->text();
    addUserCmd += " -p " + ui->lineEdit_2_p->text();
    addUserCmd += " -n " + ui->lineEdit_3_n->text();
    addUserCmd += " -m " + ui->lineEdit_4_m->text();
    addUserCmd += " -g " + ui->lineEdit_5_g->text();

    Widget::SendMessage(addUserCmd);
    QString addUserRecv = Widget::RecvMessage();
    if (addUserRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (addUserRecv == "0\n") Widget::SimpleMessageBox("写好了", "添加用户成功");
        else Widget::SimpleMessageBox("写好了", "添加用户失败");
    }
    hide();
}

AddUser::~AddUser() {
    delete ui;
}
