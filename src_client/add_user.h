#ifndef ADD_USER_H
#define ADD_USER_H

#include <QWidget>

namespace Ui {
class add_user;
}

class add_user : public QWidget
{
    Q_OBJECT

public:
    explicit add_user(QWidget *parent = nullptr);
    ~add_user();

private:
    Ui::add_user *ui;
};

#endif // ADD_USER_H
