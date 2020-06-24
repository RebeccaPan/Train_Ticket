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

    QString cmd = "modify_profile -c " + cur_username;
    cmd += " -u " + ui->lineEdit_1_u->text();
    if (ui->lineEdit_2_p->text() != "（选填）") cmd += " -p " + ui->lineEdit_2_p->text();
    if (ui->lineEdit_3_n->text() != "（选填）") cmd += " -n " + ui->lineEdit_3_n->text();
    if (ui->lineEdit_4_m->text() != "（选填）") cmd += " -m " + ui->lineEdit_4_m->text();
    if (ui->lineEdit_5_g->text() != "（选填）") cmd += " -g " + ui->lineEdit_5_g->text();

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "更改用户信息失败");
        else {
            Widget::SimpleMessageBox("写好了", "更改用户信息成功:\n" + recv);
            hide();
        }
    }
}

ModifyProfile::~ModifyProfile() {
    delete ui;
}
