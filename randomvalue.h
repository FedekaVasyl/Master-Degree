#ifndef RANDOMVALUE_H
#define RANDOMVALUE_H

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QDialogButtonBox>

namespace Ui {
class RandomValue;
}

class RandomValue : public QDialog
{
    Q_OBJECT
public slots:
    void OKClicked();
    void CancelClicked();
public:
    explicit RandomValue(QWidget *parent = 0);
    ~RandomValue();
    int sensor_random_value;

    void SetParameters();

private:
    Ui::RandomValue *ui;
    QSpinBox *sensor_random_value_spin_box;
    QPushButton *ok_button;
    QPushButton *cancel_button;
};

#endif // RANDOMVALUE_H
