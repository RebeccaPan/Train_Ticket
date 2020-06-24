#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "widget.h"
#include <QInputDialog>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget) {
    ui->setupUi(this);

    add_user_widget = new AddUser();
    add_train_widget = new AddTrain();
    modify_profile_widget = new ModifyProfile();
    ticket_operation_widget = new TicketOperation();

    ui->ticket_button->setText("query_ticket\n\nquery_transfer\n\nbuy_ticket");

    connect(ui->exit_button, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->clean_button, SIGNAL(clicked()), this, SLOT(clean()));
    connect(ui->logout_button, SIGNAL(clicked()), this, SLOT(logout()));
    connect(ui->add_user_button, SIGNAL(clicked()), this, SLOT(add_user()));
    connect(ui->add_train_button, SIGNAL(clicked()), this, SLOT(add_train()));
    connect(ui->ticket_button, SIGNAL(clicked()), this, SLOT(ticket()));
    connect(ui->query_order_button, SIGNAL(clicked()), this, SLOT(query_order()));
    connect(ui->query_train_button, SIGNAL(clicked()), this, SLOT(query_train()));
    connect(ui->delete_train_button, SIGNAL(clicked()), this, SLOT(delete_train()));
//    connect(ui->query_ticket_button, SIGNAL(clicked()), this, SLOT(query_ticket()));
    connect(ui->query_profile_button, SIGNAL(clicked()), this, SLOT(query_profile()));
    connect(ui->refund_ticket_button, SIGNAL(clicked()), this, SLOT(refund_ticket()));
    connect(ui->release_train_button, SIGNAL(clicked()), this, SLOT(release_train()));
    connect(ui->modify_profile_button, SIGNAL(clicked()), this, SLOT(modify_profile()));
//    connect(ui->query_transfer_button, SIGNAL(clicked()), this, SLOT(query_transfer()));
}

void MainWidget::init() {// Other features can also be added here.
    QString str = "Welcome, " + cur_username + "!";
    ui->label_Welcome->setText(str);
    ui->label_Welcome->repaint();
}

void MainWidget::exit() {// WARNING: 此处不区分是否成功，均退出mainwidget
    Widget::SendMessage("exit");
//    QString recv = Widget::RecvMessage();
    Widget::SimpleMessageBox("写好了", "退出程序成功");
    Widget::SimpleMessageBox("写好了", "Bye, " + cur_username + "!\nHave a nice day!");
    hide();
}

void MainWidget::clean() {// 文档要求中clean只会有0的返回值，但安全起见特判了
    Widget::SendMessage("clean");
    QString recv = Widget::RecvMessage();
    if (recv == "0\n") {
        Widget::SimpleMessageBox("写好了", "清除成功");
    }
    else {
        Widget::SimpleMessageBox("写好了", "清除失败");
    }
}

void MainWidget::logout() {
    QString logoutCmd = "logout";
    logoutCmd += " -u " + cur_username;
    Widget::SendMessage(logoutCmd);
    QString logoutRecv = Widget::RecvMessage();
    if (logoutRecv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (logoutRecv == "0\n") {
            Widget::SimpleMessageBox("写好了", "登出成功");
            Widget::SimpleMessageBox("写好了", "Bye, " + cur_username + "!\nHave a nice day!");
            hide();
        }
        else Widget::SimpleMessageBox("写好了", "登出失败");
    }
}

void MainWidget::add_user() {
    add_user_widget->cur_username = cur_username;
    add_user_widget->show();
}

void MainWidget::add_train() {
    add_train_widget->show();
}

void MainWidget::ticket() {
    ticket_operation_widget->cur_username = cur_username;
    ticket_operation_widget->show();
}

void MainWidget::query_order() {
    QString cmd = "query_order";
    cmd += " -u " + cur_username;
    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "查询订单失败");
        else Widget::SimpleMessageBox("写好了", "查询订单成功：\n" + recv);
    }
}

void MainWidget::query_train() {
    QString cmd = "query_train";

    bool ok;
    QString textDate = QInputDialog::getText(this, tr("query_train"), tr("请输入日期（格式：01-31）"), QLineEdit::Normal, "", &ok);
    if (textDate.isEmpty()) textDate = QInputDialog::getText(this, tr("delete_train"), tr("请务必输入日期（格式：01-31）"), QLineEdit::Normal, "", &ok);
    if (textDate.isEmpty()) return;
    if (ok && !textDate.isEmpty()) cmd += " -d " + textDate;

    QString textID = QInputDialog::getText(this, tr("query_train"), tr("请输入trainID"), QLineEdit::Normal, "", &ok);
    if (textID.isEmpty()) textID = QInputDialog::getText(this, tr("delete_train"), tr("请务必输入trainID"), QLineEdit::Normal, "", &ok);
    if (textID.isEmpty()) return;
    if (ok && !textID.isEmpty()) cmd += " -i " + textID;

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "查询车次失败");
        else {
            Widget::SimpleMessageBox("写好了", "查询车次成功：\n" + recv);
        }
    }
}

void MainWidget::delete_train() {
    QString cmd = "delete_train";

    bool ok;
    QString text = QInputDialog::getText(this, tr("delete_train"), tr("请输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("delete_train"), tr("请务必输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -i " + text;

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "删除车次失败");
        else {
            Widget::SimpleMessageBox("写好了", "删除车次成功");
        }
    }
}

/*void MainWidget::query_ticket() {
    ticket_operation_widget->show();
}*/

void MainWidget::query_profile() {
    QString cmd = "query_profile";
    cmd += " -c " + cur_username;

    bool ok;
    QString text = QInputDialog::getText(this, tr("query_profile"), tr("请输入username"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("query_profile"), tr("请务必输入username"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -u " + text;

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "查询个人信息失败");
        else Widget::SimpleMessageBox("写好了", "查询个人信息成功：\nUsername Name Mail Privilege\n" + recv);
    }
}

void MainWidget::refund_ticket() {
    QString cmd = "refund_ticket";
    cmd += " -u " + cur_username;

    bool ok;
    QString text = QInputDialog::getText(this, tr("refund_ticket"), tr("请输入order序号"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("refund_ticket"), tr("请务必输入order序号"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -n " + text;

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "退票失败");
        else {
            Widget::SimpleMessageBox("写好了", "退票成功");
            query_order();
        }
    }
}

void MainWidget::release_train() {
    QString cmd = "release_train";

    bool ok;
    QString text = QInputDialog::getText(this, tr("release_train"), tr("请输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) text = QInputDialog::getText(this, tr("release_train"), tr("请务必输入trainID"), QLineEdit::Normal, "", &ok);
    if (text.isEmpty()) return;
    if (ok && !text.isEmpty()) cmd += " -i " + text;

    Widget::SendMessage(cmd);
    QString recv = Widget::RecvMessage();
    if (recv == "Pigeoned") {
        Widget::SimpleMessageBox("鸽了，没收", "还没收到信息呢，也不知道成功了没有");
    }
    else {
        if (recv == "-1\n") Widget::SimpleMessageBox("写好了", "发布车次失败");
        else {
            Widget::SimpleMessageBox("写好了", "发布车次成功：\n" + text);
        }
    }
}

void MainWidget::modify_profile() {
    modify_profile_widget->cur_username = cur_username;
    modify_profile_widget->show();
}

/*void MainWidget::query_transfer() {
    ticket_operation_widget->show();
}*/


MainWidget::~MainWidget()
{
    delete ui;
    delete add_user_widget;
    delete add_train_widget;
    delete modify_profile_widget;
    delete ticket_operation_widget;
}
