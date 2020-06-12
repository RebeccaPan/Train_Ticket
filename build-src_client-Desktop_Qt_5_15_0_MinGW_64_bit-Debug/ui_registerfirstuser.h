/********************************************************************************
** Form generated from reading UI file 'registerfirstuser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERFIRSTUSER_H
#define UI_REGISTERFIRSTUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterFirstUser
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *username_inputbox;
    QLineEdit *password_inputbox;
    QLineEdit *name_inputbox;
    QLineEdit *mail_addr_inputbox;
    QPushButton *do_register;

    void setupUi(QWidget *RegisterFirstUser)
    {
        if (RegisterFirstUser->objectName().isEmpty())
            RegisterFirstUser->setObjectName(QString::fromUtf8("RegisterFirstUser"));
        RegisterFirstUser->resize(400, 300);
        label = new QLabel(RegisterFirstUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 61, 31));
        label_2 = new QLabel(RegisterFirstUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 80, 71, 41));
        label_3 = new QLabel(RegisterFirstUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 130, 54, 31));
        label_4 = new QLabel(RegisterFirstUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 190, 71, 31));
        username_inputbox = new QLineEdit(RegisterFirstUser);
        username_inputbox->setObjectName(QString::fromUtf8("username_inputbox"));
        username_inputbox->setGeometry(QRect(140, 50, 113, 20));
        password_inputbox = new QLineEdit(RegisterFirstUser);
        password_inputbox->setObjectName(QString::fromUtf8("password_inputbox"));
        password_inputbox->setGeometry(QRect(140, 90, 113, 20));
        name_inputbox = new QLineEdit(RegisterFirstUser);
        name_inputbox->setObjectName(QString::fromUtf8("name_inputbox"));
        name_inputbox->setGeometry(QRect(140, 140, 113, 20));
        mail_addr_inputbox = new QLineEdit(RegisterFirstUser);
        mail_addr_inputbox->setObjectName(QString::fromUtf8("mail_addr_inputbox"));
        mail_addr_inputbox->setGeometry(QRect(140, 200, 113, 20));
        do_register = new QPushButton(RegisterFirstUser);
        do_register->setObjectName(QString::fromUtf8("do_register"));
        do_register->setGeometry(QRect(140, 240, 80, 20));

        retranslateUi(RegisterFirstUser);

        QMetaObject::connectSlotsByName(RegisterFirstUser);
    } // setupUi

    void retranslateUi(QWidget *RegisterFirstUser)
    {
        RegisterFirstUser->setWindowTitle(QCoreApplication::translate("RegisterFirstUser", "\346\263\250\345\206\214\347\254\254\344\270\200\344\270\252\347\224\250\346\210\267", nullptr));
        label->setText(QCoreApplication::translate("RegisterFirstUser", "username", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterFirstUser", "password", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterFirstUser", "name", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterFirstUser", "mail_addr", nullptr));
        do_register->setText(QCoreApplication::translate("RegisterFirstUser", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterFirstUser: public Ui_RegisterFirstUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERFIRSTUSER_H
