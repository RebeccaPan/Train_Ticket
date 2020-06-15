#ifndef MODIFY_PROFILE_H
#define MODIFY_PROFILE_H

#include <QWidget>

namespace Ui {
class ModifyProfile;
}

class ModifyProfile : public QWidget {
    Q_OBJECT

public:
    explicit ModifyProfile(QWidget *parent = nullptr);
    ~ModifyProfile();

private slots:
    void do_modify_profile();

private:
    Ui::ModifyProfile *ui;

public:
    QString cur_username;
};

#endif // MODIFY_PROFILE_H
