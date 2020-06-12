#include "widget.h"
#include "ui_widget.h"

QTcpSocket *Widget::socket = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    assert( socket == nullptr );
    socket = new QTcpSocket();
    login_widget = new LoginWidget();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(connect_server()));
}

Widget::~Widget()
{
    delete ui;
    delete socket;
    delete login_widget;
}

void Widget::connect_server() {
    PigeonBox(); // TODO

    SimpleMessageBox("实际上还没写呢", "连接成功");
    hide();
    login_widget->show();
}

void Widget::SimpleMessageBox( const QString &title, const QString &text ) {
    QMessageBox tmp_box;
    tmp_box.setWindowTitle(title);
    tmp_box.setText(text);
    tmp_box.exec();
}

void Widget::PigeonBox() {
    SimpleMessageBox("鸽了", "没写呢，啊还没写呢");
}

void Widget::SendMessage( const QString &msg ) {
    SimpleMessageBox("鸽了，没送", msg); // TODO
}

QString Widget::RecvMessage() { // "over" if over
    return "Pigeoned"; // TODO
}

