#include "add_user.h"
#include "ui_add_user.h"
#include "widget.h"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser) {
    ui->setupUi(this);

    connect(ui->do_add_user, SIGNAL(clicked()), this, SLOT(do_add_user()));
}

void AddUser::do_add_user() {
    Widget::PigeonBox(); // TODO
    Widget::SimpleMessageBox("还没完成", "添加用户成功");
    hide();
}

AddUser::~AddUser() {
    delete ui;
}
