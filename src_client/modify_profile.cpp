#include "modify_profile.h"
#include "ui_modify_profile.h"
#include "widget.h"

ModifyProfile::ModifyProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyProfile) {
    ui->setupUi(this);

    connect(ui->do_modify_profile, SIGNAL(clicked()), this, SLOT(do_modify_profile()));
}

void ModifyProfile::do_modify_profile() {
    if(ui->lineEdit_1_u->text() == "") {Widget::SimpleMessageBox("", "请填写username"); return;}
    if(ui->lineEdit_2_p->text() == "") {Widget::SimpleMessageBox("", "请填写password"); return;}
    if(ui->lineEdit_3_n->text() == "") {Widget::SimpleMessageBox("", "请填写name"); return;}
    if(ui->lineEdit_4_m->text() == "") {Widget::SimpleMessageBox("", "请填写mailAddr"); return;}
    if(ui->lineEdit_5_g->text() == "") {Widget::SimpleMessageBox("", "请填写privilege"); return;}

    QString addUserCmd = "modify_profile -c " + cur_username;
    addUserCmd += " -u " + ui->lineEdit_1_u->text();
    if (ui->lineEdit_2_p->text() != "（选填）") addUserCmd += " -p " + ui->lineEdit_2_p->text();
    if (ui->lineEdit_3_n->text() != "（选填）") addUserCmd += " -n " + ui->lineEdit_3_n->text();
    if (ui->lineEdit_4_m->text() != "（选填）") addUserCmd += " -m " + ui->lineEdit_4_m->text();
    if (ui->lineEdit_5_g->text() != "（选填）") addUserCmd += " -g " + ui->lineEdit_5_g->text();

    Widget::SendMessage(addUserCmd);
    QString addUserRecv = Widget::RecvMessage();
    if (addUserRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (addUserRecv == "0\n") Widget::SimpleMessageBox("实际上还没写呢", "添加用户成功");
        else Widget::SimpleMessageBox("实际上还没写呢", "添加用户失败");
    }
    hide();
}

ModifyProfile::~ModifyProfile() {
    delete ui;
}
