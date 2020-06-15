#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "add_user.h"
#include "add_train.h"
#include "modify_profile.h"
#include "ticket_operation.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void init();
    ~MainWidget();

private slots:
    void exit();
    void clean();
    void logout();
    void add_user();
    void add_train();
    void ticket();
    void query_order();
    void query_train();
    void delete_train();
//    void query_ticket();
    void query_profile();
    void refund_ticket();
    void release_train();
    void modify_profile();
//    void query_transfer();

private:
    Ui::MainWidget *ui;
    AddUser *add_user_widget;
    AddTrain *add_train_widget;
    ModifyProfile *modify_profile_widget;
    TicketOperation *ticket_operation_widget;

public:
    QString cur_username;
};

#endif // MAINWIDGET_H
