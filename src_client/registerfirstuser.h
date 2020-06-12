#ifndef REGISTERFIRSTUSER_H
#define REGISTERFIRSTUSER_H

#include <QWidget>

namespace Ui {
class RegisterFirstUser;
}

class RegisterFirstUser : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterFirstUser(QWidget *parent = nullptr);
    ~RegisterFirstUser();

private slots:
    void do_register();

private:
    Ui::RegisterFirstUser *ui;
};

#endif // REGISTERFIRSTUSER_H
