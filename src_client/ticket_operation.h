#ifndef TICKET_OPERATION_H
#define TICKET_OPERATION_H

#include <QWidget>

namespace Ui {
class TicketOperation;
}

class TicketOperation : public QWidget {
    Q_OBJECT

public:
    explicit TicketOperation(QWidget *parent = nullptr);
    ~TicketOperation();

private slots:
    void do_query_ticket();
    void do_query_transfer();
    void do_buy_ticket();

private:
    Ui::TicketOperation *ui;

public:
    QString cur_username;
};

#endif // TICKET_OPERATION_H
