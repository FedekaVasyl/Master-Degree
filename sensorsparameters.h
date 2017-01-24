#ifndef SENSORSPARAMETERS_H
#define SENSORSPARAMETERS_H

#include <QDialog>

namespace Ui {
class SensorsParameters;
}

class SensorsParameters : public QDialog
{
    Q_OBJECT

public:
    explicit SensorsParameters(QWidget *parent = 0);
    ~SensorsParameters();

private:
    Ui::SensorsParameters *ui;
};

#endif // SENSORSPARAMETERS_H
