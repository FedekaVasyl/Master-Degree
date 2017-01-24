#include "energyvalue.h"
#include "ui_energyvalue.h"

EnergyValue::EnergyValue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnergyValue)
{
    ui->setupUi(this);

    this->initial_energy_label = ui->initial_energy_label;
    this->receive_power_label = ui->receive_power_label;
    this->transfer_power_label = ui->transfer_power_label;
    this->active_power_label = ui->active_power_label;
    this->sleep_power_label = ui->sleep_power_label;
    this->initial_energy_spin_box = ui->initial_energy_spin_box;
    this->receive_power_spin_box = ui->receive_power_spin_box;
    this->transfer_power_spin_box = ui->transfer_power_spin_box;
    this->active_power_spin_box = ui->active_power_spin_box_2;
    this->sleep_power_spin_box = ui->sleep_power_spin_box;

    this->dialog_button_box = ui->dialog_button_box;
    this->random_button = ui->random_button;
    this->ok_button = ui->dialog_button_box->button(QDialogButtonBox::Ok);
    this->cancel_button = ui->dialog_button_box->button(QDialogButtonBox::Cancel);

    QObject::connect(this->random_button,SIGNAL(clicked(bool)),\
                     this,SLOT(RandomValue()));
    QObject::connect(this->ok_button,SIGNAL(clicked(bool)),\
                     this,SLOT(OKClicked()));
    QObject::connect(this->cancel_button,SIGNAL(clicked(bool)),\
                     this,SLOT(CancelClicked()));
    SetParameters();
}

EnergyValue::~EnergyValue()
{
    delete ui;
}


QLabel* EnergyValue::GetInitialEnergyLabel() const
{
    return this->initial_energy_label;
}

QLabel* EnergyValue::GetReceivePowerLabel() const
{
    return this->receive_power_label;
}

QLabel* EnergyValue::GetTransferPowerLabel() const
{
    return this->transfer_power_label;
}

QLabel* EnergyValue::GetActivePowerLabel() const
{
    return this->active_power_label;
}

QLabel* EnergyValue::GetSleepPowerLabel() const
{
    return this->sleep_power_label;
}

QSpinBox* EnergyValue::GetInitialEnergySpinBox() const
{
    return this->initial_energy_spin_box;
}

QSpinBox* EnergyValue::GetReceivePowerSpinBox() const
{
    return this->receive_power_spin_box;
}

QSpinBox* EnergyValue::GetTransferPowerSpinBox() const
{
    return this->transfer_power_spin_box;
}

QSpinBox* EnergyValue::GetActivePowerSpinBox() const
{
    return this->active_power_spin_box;
}

QSpinBox* EnergyValue::GetSleepPowerSpinBox() const
{
    return this->sleep_power_spin_box;
}

QDialogButtonBox* EnergyValue::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* EnergyValue::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* EnergyValue::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* EnergyValue::GetCancelButton() const
{
    return this->cancel_button;
}

void EnergyValue::SetInitialEnergyLabel(QLabel *_initial_energy_label)
{
    this->initial_energy_label = _initial_energy_label;
}

void EnergyValue::SetReceivePowerLabel(QLabel *_receive_power_label)
{
    this->receive_power_label = _receive_power_label;
}

void EnergyValue::SetTransferPowerLabel(QLabel *_transfer_power_label)
{
    this->transfer_power_label = _transfer_power_label;
}

void EnergyValue::SetActivePowerLabel(QLabel *_active_power_label)
{
    this->active_power_label = _active_power_label;
}

void EnergyValue::SetSleepPowerLabel(QLabel *_sleep_power_label)
{
    this->sleep_power_label = _sleep_power_label;
}

void EnergyValue::SetInitialEnergySpinBox(QSpinBox *_initial_energy_spin_box)
{
    this->initial_energy_spin_box = _initial_energy_spin_box;
}

void EnergyValue::SetReceivePowerSpinBox(QSpinBox *_receive_power_spin_box)
{
    this->receive_power_spin_box = _receive_power_spin_box;
}

void EnergyValue::SetTransferPowerSpinBox(QSpinBox *_transfer_power_spin_box)
{
    this->transfer_power_spin_box = _transfer_power_spin_box;
}

void EnergyValue::SetActivePowerSpinBox(QSpinBox *_active_power_spin_box)
{
    this->active_power_spin_box = _active_power_spin_box;
}

void EnergyValue::SetSleepPowerSpinBox(QSpinBox *_sleep_power_spin_box)\
{
    this->sleep_power_spin_box = _sleep_power_spin_box;
}

void EnergyValue::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void EnergyValue::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void EnergyValue::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void EnergyValue::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

double EnergyValue::GetInitialEnergy() const
{
    return this->initial_energy;
}

int EnergyValue::GetReceivePower() const
{
    return this->receive_power;
}

int EnergyValue::GetTransferPower() const
{
    return this->transfer_power;
}

int EnergyValue::GetActivePower() const
{
    return this->active_power;
}

int EnergyValue::GetSleepPower() const
{
    return this->sleep_power;
}

void EnergyValue::SetInitialEnergy(double _initial_energy)
{
    this->initial_energy = _initial_energy;
}

void EnergyValue::SetReceivePower(int _receive_power)
{
    this->receive_power = _receive_power;
}

void EnergyValue::SetTransferPower(int _transfer_power)
{
    this->transfer_power = _transfer_power;
}

void EnergyValue::SetActivePower(int _active_power)
{
    this->active_power = _active_power;
}

void EnergyValue::SetSleepPower(int _sleep_power)
{
    this->sleep_power = _sleep_power;
}


void EnergyValue::RandomValue()
{
    int _initial_energy;
    int _receive_power;
    int _transfer_power;
    int _active_power;
    int _sleep_power;
    srand(time(0));
    _initial_energy = this->initial_energy_spin_box->minimum() + \
                    rand() % this->initial_energy_spin_box->maximum() + 1;
    _receive_power = this->receive_power_spin_box->minimum() + \
                    rand() % this->receive_power_spin_box->maximum() + 1;
    _transfer_power = this->transfer_power_spin_box->minimum() + \
                    rand() % this->transfer_power_spin_box->maximum() + 1;
    _active_power = this->active_power_spin_box->minimum() + \
                    rand() % this->active_power_spin_box->maximum() + 1;
    _sleep_power = this->sleep_power_spin_box->minimum() + \
                    rand() % this->sleep_power_spin_box->maximum() + 1;
    this->initial_energy_spin_box->setValue(_initial_energy);
    this->receive_power_spin_box->setValue(_receive_power);
    this->transfer_power_spin_box->setValue(_transfer_power);
    this->active_power_spin_box->setValue(_active_power);
    this->sleep_power_spin_box->setValue(_sleep_power);
}

void EnergyValue::SetParameters()
{
    this->initial_energy = this->initial_energy_spin_box->value() * 1000.0;
    this->receive_power = this->receive_power_spin_box->value();
    this->transfer_power = this->transfer_power_spin_box->value();
    this->active_power = this->active_power_spin_box->value();
    this->sleep_power = this->sleep_power_spin_box->value();
}

void EnergyValue::OKClicked()
{
    SetParameters();
    this->hide();
}

void EnergyValue::CancelClicked()
{
    this->hide();
}

double EnergyValue::GetNeighborsFoundEnergyReceive() const
{
    return this->neighbors_found_energy_receive;
}

void EnergyValue::SetNeighborsFoundEnergyReceive(double _energy)
{
    this->neighbors_found_energy_receive = _energy;
}

void EnergyValue::CalculateNeighborsFoundEnergyReceive(double t_wait, double t_cca, double t_data, double t_ack)
{
    double e = this->GetActivePower() * t_wait + \
               this->GetReceivePower() * t_cca + \
               this->GetReceivePower() * t_data + \
               this->GetReceivePower() * t_ack;
    this->SetNeighborsFoundEnergyReceive(e / 1000.0);
}

double EnergyValue::GetNeighborsFoundEnergyTransfer() const
{
    return this->neighbors_found_energy_transfer;
}

void EnergyValue::SetNeighborsFoundEnergyTransfer(double _energy)
{
    this->neighbors_found_energy_transfer = _energy;
}

void EnergyValue::CalculateNeighborsFoundEnergyTransfer(double t_wait, double t_cca, double t_data, double t_ack)
{
    double e = this->GetActivePower() * t_wait + \
               this->GetReceivePower() * t_cca + \
               this->GetTransferPower() * t_data + \
               this->GetReceivePower() * t_ack;
    this->SetNeighborsFoundEnergyTransfer(e / 1000.0);
}

double EnergyValue::GetConsumedEnergy() const
{
    return this->consumed_energy;
}

void EnergyValue::SetConsumedEnergy(double _energy)
{
    this->consumed_energy = _energy;
}

void EnergyValue::CalculateConsumedEnergy(double t_proc, double t_sleep)
{
    double energy;
    energy = double(this->GetActivePower()) * t_proc / 1000.0 + \
             double(this->GetSleepPower()) * t_sleep / 1000000.0;
    this->SetConsumedEnergy(energy);
}

