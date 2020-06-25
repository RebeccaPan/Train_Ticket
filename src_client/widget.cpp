#include "widget.h"
#include "ui_widget.h"
#include <QtTest>

QTcpSocket *Widget::socket = nullptr;

bool isDeveloper = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/Main"));

    assert( socket == nullptr );
    socket = new QTcpSocket();
    login_widget = new LoginWidget();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(connect_server()));
}

Widget::~Widget() {
    delete ui;
    delete socket;
    delete login_widget;
}

void Widget::connect_server() {
    socket->connectToHost(ui->lineEdit->text(), 11031);
    if( socket->waitForConnected(5000) ) {
        SimpleMessageBox("砬对话框", "连接成功\nConnected");
        hide();
        login_widget->show();
    } else {
        SimpleMessageBox("针难人对话框", "你在开玩笑\nConnection Failure");
    }
}

void Widget::SimpleMessageBox( const QString &title, const QString &text ) {
    QMessageBox tmp_box;
    tmp_box.setWindowIcon(QIcon(":/new/prefix1/Main"));
    tmp_box.setWindowTitle(title);
    tmp_box.setText(text);
    tmp_box.exec();
}

void Widget::PigeonBox() {
    SimpleMessageBox("鸽了", "没写呢，啊还没写呢");
}

void Widget::SendMessage( const QString &msg ) {
    if (isDeveloper == 1) {Widget::SimpleMessageBox("开发者模式中/Developer mode", msg);}
    if( socket->state() == QAbstractSocket::ConnectedState ) {
        socket->write(msg.toUtf8());
        int tmp = 0;
        socket->write( reinterpret_cast<char*>(&tmp), 4 );
        socket->flush();
//        Widget::SimpleMessageBox("砬对话框", "送出去了");
    } else {
        Widget::SimpleMessageBox("针难人对话框", "服务器鸽了，关闭程序\nThe server is offline.");
        exit(0);
    }
}

QString Widget::RecvMessage() { // "over" if over
    if( socket->state() == QAbstractSocket::ConnectedState ) {
        QByteArray buffer;
        while(1) {
//            Widget::SimpleMessageBox("cerr", "here1");
            buffer = socket->readAll();
            if( buffer.isEmpty() == false ) break;
            QTest::qWait(1000);
        }
        QString ans = buffer;
        while(1) {
//            Widget::SimpleMessageBox("cerr", "here2");
            buffer = socket->readAll();
            if( buffer.isEmpty() ) break;
            ans += buffer;
            QTest::qWait(1000);
        }
        return ans;
    } else {
        Widget::SimpleMessageBox("针难人对话框", "服务器鸽了，关闭程序\nThe server is offline.");
        exit(0);
        return QString();
    }
}

void Widget::on_developerCheck_stateChanged(int arg1) {
    isDeveloper = 1-isDeveloper;
}
