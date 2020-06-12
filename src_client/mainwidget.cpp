#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "widget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    connect(ui->exit_button, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->clean_button, SIGNAL(clicked()), this, SLOT(clean()));
    connect(ui->logout_button, SIGNAL(clicked()), this, SLOT(logout()));
    connect(ui->add_user_button, SIGNAL(clicked()), this, SLOT(add_user()));
    connect(ui->add_train_button, SIGNAL(clicked()), this, SLOT(add_train()));
    connect(ui->buy_ticket_button, SIGNAL(clicked()), this, SLOT(buy_ticket()));
    connect(ui->query_order_button, SIGNAL(clicked()), this, SLOT(query_order()));
    connect(ui->query_train_button, SIGNAL(clicked()), this, SLOT(query_train()));
    connect(ui->delete_train_button, SIGNAL(clicked()), this, SLOT(delete_train()));
    connect(ui->query_ticket_button, SIGNAL(clicked()), this, SLOT(query_ticket()));
    connect(ui->query_profile_button, SIGNAL(clicked()), this, SLOT(query_profile()));
    connect(ui->refund_ticket_button, SIGNAL(clicked()), this, SLOT(refund_ticket()));
    connect(ui->release_train_button, SIGNAL(clicked()), this, SLOT(release_train()));
    connect(ui->modify_profile_button, SIGNAL(clicked()), this, SLOT(modify_profile()));
    connect(ui->query_transfer_button, SIGNAL(clicked()), this, SLOT(query_transfer()));
}

void MainWidget::exit() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::clean() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::logout() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::add_user() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::add_train() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::buy_ticket() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::query_order() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::query_train() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::delete_train() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::query_ticket() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::query_profile() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::refund_ticket() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::release_train() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::modify_profile() {
    Widget::PigeonBox(); // TODO
}

void MainWidget::query_transfer() {
    Widget::PigeonBox(); // TODO
}


MainWidget::~MainWidget()
{
    delete ui;
}
