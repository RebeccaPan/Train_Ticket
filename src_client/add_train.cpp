#include "add_train.h"
#include "ui_add_train.h"
#include "widget.h"

AddTrain::AddTrain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTrain) {
    ui->setupUi(this);

    connect(ui->do_add_train, SIGNAL(clicked()), this, SLOT(do_add_train()));
}

void AddTrain::do_add_train() {
    if(ui->lineEdit_0_i->text() == "") {Widget::SimpleMessageBox("", "请填写trainID"); return;}
    if(ui->lineEdit_1_n->text() == "") {Widget::SimpleMessageBox("", "请填写stationNum"); return;}
    if(ui->lineEdit_2_m->text() == "") {Widget::SimpleMessageBox("", "请填写seatNum"); return;}
    if(ui->lineEdit_3_s->text() == "") {Widget::SimpleMessageBox("", "请填写stations"); return;}
    if(ui->lineEdit_4_p->text() == "") {Widget::SimpleMessageBox("", "请填写prices"); return;}
    if(ui->lineEdit_5_x->text() == "") {Widget::SimpleMessageBox("", "请填写startTime"); return;}
    if(ui->lineEdit_6_t->text() == "") {Widget::SimpleMessageBox("", "请填写travelTimes"); return;}
    if(ui->lineEdit_7_o->text() == "") {Widget::SimpleMessageBox("", "请填写stopoverTimes"); return;}
    if(ui->lineEdit_8_d->text() == "") {Widget::SimpleMessageBox("", "请填写saleDate"); return;}
    if(ui->lineEdit_9_y->text() == "") {Widget::SimpleMessageBox("", "请填写type"); return;}

    QString addTrainCmd = "add_train";
    addTrainCmd += " -i " + ui->lineEdit_0_i->text();
    addTrainCmd += " -n " + ui->lineEdit_1_n->text();
    addTrainCmd += " -m " + ui->lineEdit_2_m->text();
    addTrainCmd += " -s " + ui->lineEdit_3_s->text();
    addTrainCmd += " -p " + ui->lineEdit_4_p->text();
    addTrainCmd += " -x " + ui->lineEdit_5_x->text();
    addTrainCmd += " -t " + ui->lineEdit_6_t->text();
    addTrainCmd += " -o " + ui->lineEdit_7_o->text();
    addTrainCmd += " -d " + ui->lineEdit_8_d->text();
    addTrainCmd += " -y " + ui->lineEdit_9_y->text();

    Widget::SendMessage(addTrainCmd);
    QString addTrainRecv = Widget::RecvMessage();
    if (addTrainRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (addTrainRecv == "0\n") Widget::SimpleMessageBox("写好了", "添加车次成功");
        else Widget::SimpleMessageBox("写好了", "添加车次失败");
    }
    hide();
}

AddTrain::~AddTrain() {
    delete ui;
}
