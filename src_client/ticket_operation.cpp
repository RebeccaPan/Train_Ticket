#include "ticket_operation.h"
#include "ui_ticket_operation.h"
#include "widget.h"
#include "QInputDialog"

TicketOperation::TicketOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketOperation) {
    ui->setupUi(this);

    connect(ui->do_1query , SIGNAL(clicked()), this, SLOT(do_query_ticket()));
    connect(ui->do_2transfer, SIGNAL(clicked()), this, SLOT(do_query_transfer()));
    connect(ui->do_3buy, SIGNAL(clicked()), this, SLOT(do_buy_ticket()));
}

void TicketOperation::do_query_ticket() {
    if(ui->lineEdit_date->text() == "") {Widget::SimpleMessageBox("", "请填写date"); return;}
    if(ui->lineEdit_to  ->text() == "") {Widget::SimpleMessageBox("", "请填写to"); return;}
    if(ui->lineEdit_from->text() == "") {Widget::SimpleMessageBox("", "请填写from"); return;}

    QString queryTicketCmd = "query_ticket";
    queryTicketCmd += " -s " + ui->lineEdit_from->text();
    queryTicketCmd += " -t " + ui->lineEdit_to->text();
    queryTicketCmd += " -d " + ui->lineEdit_date->text();

    // TODO -p time/cost
    /*bool ok;
    QString text = QInputDialog::getText(this, tr("refund_ticket"), tr("请输入order序号"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("refund_ticket"), tr("请务必输入order序号"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) queryTicketCmd += " -p " + text;*/

    QStringList items;
    items << tr("time") << tr("cost");
    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("Do you prefer shortest time first or lowest cost first?"), items, 0, false, &ok);
    if (item.isEmpty()) item = "time";
    if (ok && !item.isEmpty()) {
        queryTicketCmd += " -p " + item;
    }

    Widget::SendMessage(queryTicketCmd);
    QString queryTicketRecv = Widget::RecvMessage();
    if (queryTicketRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (queryTicketRecv == "0\n") Widget::SimpleMessageBox("写好了", "查票成功");
        else Widget::SimpleMessageBox("写好了", "查票失败");
    }
}

void TicketOperation::do_query_transfer() {
    if(ui->lineEdit_date->text() == "") {Widget::SimpleMessageBox("", "请填写date"); return;}
    if(ui->lineEdit_to  ->text() == "") {Widget::SimpleMessageBox("", "请填写to"); return;}
    if(ui->lineEdit_from->text() == "") {Widget::SimpleMessageBox("", "请填写from"); return;}

    QString queryTransferCmd = "query_transfer";
    queryTransferCmd += " -s " + ui->lineEdit_from->text();
    queryTransferCmd += " -t " + ui->lineEdit_to->text();
    queryTransferCmd += " -d " + ui->lineEdit_date->text();

    QStringList items;
    items << tr("time") << tr("cost");
    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("Do you prefer shortest time first or lowest cost first?"), items, 0, false, &ok);
    if (item.isEmpty()) item = "time";
    if (ok && !item.isEmpty()) {
        queryTransferCmd += " -p " + item;
    }

    Widget::SendMessage(queryTransferCmd);
    QString queryTransferRecv = Widget::RecvMessage();
    if (queryTransferRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (queryTransferRecv == "0\n") Widget::SimpleMessageBox("写好了", "查换乘票成功");
        else Widget::SimpleMessageBox("写好了", "查换乘票失败");
    }
}

void TicketOperation::do_buy_ticket() {
    QString cmd = "buy_ticket -u " + cur_username;

    if(ui->lineEdit_date->text() == "") {Widget::SimpleMessageBox("", "请填写date"); return;}
    if(ui->lineEdit_to  ->text() == "") {Widget::SimpleMessageBox("", "请填写to"); return;}
    if(ui->lineEdit_from->text() == "") {Widget::SimpleMessageBox("", "请填写from"); return;}

    bool ok;
    QString text = QInputDialog::getText(this, tr("buy_ticket"), tr("请输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("buy_ticket"), tr("请务必输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -i " + text;

    cmd += " -d " + ui->lineEdit_date->text();

    text = QInputDialog::getText(this, tr("buy_ticket"), tr("请输入买票数量"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("buy_ticket"), tr("请务必输入买票数量"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -n " + text;

    cmd += " -f " + ui->lineEdit_from->text();
    cmd += " -t " + ui->lineEdit_to->text();

    QStringList items;
    items << tr("Yes") << tr("No");
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"), tr("Do you accept queuing if there's not enough seats?"), items, 0, false, &ok);
    if (item.isEmpty() || item == "Yes") item = "true";
    else item = "false";
    if (ok && !item.isEmpty()) {
        cmd += " -q " + item;
    }

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "0\n") Widget::SimpleMessageBox("写好了", "购票成功");
        else Widget::SimpleMessageBox("写好了", "购票失败");
    }
}

TicketOperation::~TicketOperation() {
    delete ui;
}
