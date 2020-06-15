#ifndef ADD_TRAIN_H
#define ADD_TRAIN_H

#include <QWidget>

namespace Ui {
class AddTrain;
}

class AddTrain : public QWidget {
    Q_OBJECT

public:
    explicit AddTrain(QWidget *parent = nullptr);
    ~AddTrain();

private slots:
    void do_add_train();

private:
    Ui::AddTrain *ui;
};

#endif // ADD_TRAIN_H
