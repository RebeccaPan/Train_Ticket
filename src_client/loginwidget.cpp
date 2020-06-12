#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "widget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    main_widget = new MainWidget();
    register_first_user_widget = new RegisterFirstUser();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(register_first_user()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(login()));
}

LoginWidget::~LoginWidget()
{
    delete ui;
    delete main_widget;
    delete register_first_user_widget;
}

void LoginWidget::register_first_user() {
    register_first_user_widget->show();
}

void LoginWidget::login() {
    Widget::PigeonBox(); // TODO

    Widget::SimpleMessageBox("实际上还没写呢", "登陆成功");
    hide();
    main_widget->show();
}
