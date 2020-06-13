#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void exit();
    void clean();
    void logout();
    void add_user();
    void add_train();
    void buy_ticket();
    void query_order();
    void query_train();
    void delete_train();
    void query_ticket();
    void query_profile();
    void refund_ticket();
    void release_train();
    void modify_profile();
    void query_transfer();

private:
    Ui::MainWidget *ui;

};

#endif // MAINWIDGET_H
