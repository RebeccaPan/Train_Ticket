#ifndef ADD_USER_H
#define ADD_USER_H

#include <QWidget>

namespace Ui {
class AddUser;
}

class AddUser : public QWidget {
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();

private slots:
    void do_add_user();

private:
    Ui::AddUser *ui;
};

#endif // ADD_USER_H
