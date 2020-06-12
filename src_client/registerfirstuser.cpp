#include "registerfirstuser.h"
#include "ui_registerfirstuser.h"
#include "widget.h"

RegisterFirstUser::RegisterFirstUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterFirstUser)
{
    ui->setupUi(this);

    connect(ui->do_register, SIGNAL(clicked()), this, SLOT(do_register()));
}

void RegisterFirstUser::do_register() {
    Widget::PigeonBox(); // TODO

    Widget::SimpleMessageBox("实际上还没写呢", "注册成功");
    hide();
}

RegisterFirstUser::~RegisterFirstUser()
{
    delete ui;
}
