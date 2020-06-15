#ifndef MODIFY_USER_H
#define MODIFY_USER_H

#include <QWidget>

namespace Ui {
class ModifyUser;
}

class ModifyUser : public QWidget {
    Q_OBJECT

public:
    explicit ModifyUser(QWidget *parent = nullptr);
    ~ModifyUser();

private slots:
    void do_modify_profile();

private:
    Ui::ModifyUser *ui;
};

#endif // MODIFY_USER_H
