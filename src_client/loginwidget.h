#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

#include "mainwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void register_first_user();
    void login();

private:
    Ui::LoginWidget *ui;
    MainWidget *main_widget;
};

#endif // LOGINWIDGET_H
