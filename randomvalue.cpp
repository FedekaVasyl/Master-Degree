#include "randomvalue.h"
#include "ui_randomvalue.h"

RandomValue::RandomValue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomValue)
{
    ui->setupUi(this);
    this->ok_button = ui->dialog_button_box->button(QDialogButtonBox::Ok);
    this->cancel_button = ui->dialog_button_box->button(QDialogButtonBox::Cancel);
    this->sensor_random_value_spin_box = ui->spinBox_4;
    this->sensor_random_value = this->sensor_random_value_spin_box->value();
    QObject::connect(this->ok_button,SIGNAL(clicked(bool)),\
                     this,SLOT(OKClicked()));
    QObject::connect(this->cancel_button,SIGNAL(clicked(bool)),\
                     this,SLOT(CancelClicked()));
}

RandomValue::~RandomValue()
{
    delete ui;
}

void RandomValue::OKClicked()
{
    SetParameters();
    this->hide();
}

void RandomValue::CancelClicked()
{
    this->hide();
}

void RandomValue::SetParameters()
{
    this->sensor_random_value = this->sensor_random_value_spin_box->value();
}
