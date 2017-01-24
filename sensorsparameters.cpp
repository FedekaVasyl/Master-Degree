#include "sensorsparameters.h"
#include "ui_sensorsparameters.h"

SensorsParameters::SensorsParameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SensorsParameters)
{
    ui->setupUi(this);
}

SensorsParameters::~SensorsParameters()
{
    delete ui;
}
