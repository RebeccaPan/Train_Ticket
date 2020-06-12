/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *add_user_button;
    QPushButton *logout_button;
    QPushButton *query_profile_button;
    QPushButton *modify_profile_button;
    QPushButton *add_train_button;
    QPushButton *release_train_button;
    QPushButton *query_train_button;
    QPushButton *delete_train_button;
    QPushButton *query_ticket_button;
    QPushButton *query_transfer_button;
    QPushButton *buy_ticket_button;
    QPushButton *query_order_button;
    QPushButton *refund_ticket_button;
    QPushButton *clean_button;
    QPushButton *exit_button;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(400, 300);
        add_user_button = new QPushButton(MainWidget);
        add_user_button->setObjectName(QString::fromUtf8("add_user_button"));
        add_user_button->setGeometry(QRect(50, 40, 80, 31));
        logout_button = new QPushButton(MainWidget);
        logout_button->setObjectName(QString::fromUtf8("logout_button"));
        logout_button->setGeometry(QRect(150, 40, 80, 31));
        query_profile_button = new QPushButton(MainWidget);
        query_profile_button->setObjectName(QString::fromUtf8("query_profile_button"));
        query_profile_button->setGeometry(QRect(250, 40, 101, 31));
        modify_profile_button = new QPushButton(MainWidget);
        modify_profile_button->setObjectName(QString::fromUtf8("modify_profile_button"));
        modify_profile_button->setGeometry(QRect(50, 90, 111, 31));
        add_train_button = new QPushButton(MainWidget);
        add_train_button->setObjectName(QString::fromUtf8("add_train_button"));
        add_train_button->setGeometry(QRect(180, 90, 80, 31));
        release_train_button = new QPushButton(MainWidget);
        release_train_button->setObjectName(QString::fromUtf8("release_train_button"));
        release_train_button->setGeometry(QRect(280, 90, 101, 31));
        query_train_button = new QPushButton(MainWidget);
        query_train_button->setObjectName(QString::fromUtf8("query_train_button"));
        query_train_button->setGeometry(QRect(50, 140, 91, 31));
        delete_train_button = new QPushButton(MainWidget);
        delete_train_button->setObjectName(QString::fromUtf8("delete_train_button"));
        delete_train_button->setGeometry(QRect(160, 140, 91, 31));
        query_ticket_button = new QPushButton(MainWidget);
        query_ticket_button->setObjectName(QString::fromUtf8("query_ticket_button"));
        query_ticket_button->setGeometry(QRect(270, 140, 101, 31));
        query_transfer_button = new QPushButton(MainWidget);
        query_transfer_button->setObjectName(QString::fromUtf8("query_transfer_button"));
        query_transfer_button->setGeometry(QRect(50, 190, 101, 31));
        buy_ticket_button = new QPushButton(MainWidget);
        buy_ticket_button->setObjectName(QString::fromUtf8("buy_ticket_button"));
        buy_ticket_button->setGeometry(QRect(170, 190, 101, 31));
        query_order_button = new QPushButton(MainWidget);
        query_order_button->setObjectName(QString::fromUtf8("query_order_button"));
        query_order_button->setGeometry(QRect(290, 190, 91, 31));
        refund_ticket_button = new QPushButton(MainWidget);
        refund_ticket_button->setObjectName(QString::fromUtf8("refund_ticket_button"));
        refund_ticket_button->setGeometry(QRect(50, 240, 101, 31));
        clean_button = new QPushButton(MainWidget);
        clean_button->setObjectName(QString::fromUtf8("clean_button"));
        clean_button->setGeometry(QRect(170, 240, 80, 31));
        exit_button = new QPushButton(MainWidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(270, 240, 80, 31));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "12305", nullptr));
        add_user_button->setText(QCoreApplication::translate("MainWidget", "add_user", nullptr));
        logout_button->setText(QCoreApplication::translate("MainWidget", "logout", nullptr));
        query_profile_button->setText(QCoreApplication::translate("MainWidget", "query_profile", nullptr));
        modify_profile_button->setText(QCoreApplication::translate("MainWidget", "modify_profile", nullptr));
        add_train_button->setText(QCoreApplication::translate("MainWidget", "add_train", nullptr));
        release_train_button->setText(QCoreApplication::translate("MainWidget", "release_train", nullptr));
        query_train_button->setText(QCoreApplication::translate("MainWidget", "query_train", nullptr));
        delete_train_button->setText(QCoreApplication::translate("MainWidget", "delete_train", nullptr));
        query_ticket_button->setText(QCoreApplication::translate("MainWidget", "query_ticket", nullptr));
        query_transfer_button->setText(QCoreApplication::translate("MainWidget", "query_transfer", nullptr));
        buy_ticket_button->setText(QCoreApplication::translate("MainWidget", "buy_ticket", nullptr));
        query_order_button->setText(QCoreApplication::translate("MainWidget", "query_order", nullptr));
        refund_ticket_button->setText(QCoreApplication::translate("MainWidget", "refund_ticket", nullptr));
        clean_button->setText(QCoreApplication::translate("MainWidget", "clean", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWidget", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
