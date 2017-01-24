#ifndef ENERGYVALUE_H
#define ENERGYVALUE_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <ctime>
#include <random>
#include <iostream>

namespace Ui {
class EnergyValue;
}

class EnergyValue : public QDialog
{
    Q_OBJECT
public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();
private:
    Ui::EnergyValue *ui;

    QLabel *initial_energy_label;
    QLabel *receive_power_label;
    QLabel *transfer_power_label;
    QLabel *active_power_label;
    QLabel *sleep_power_label;
    QSpinBox *initial_energy_spin_box;
    QSpinBox *receive_power_spin_box;
    QSpinBox *transfer_power_spin_box;
    QSpinBox *active_power_spin_box;
    QSpinBox *sleep_power_spin_box;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    double initial_energy;
    int receive_power;
    int transfer_power;
    int active_power;
    int sleep_power;


    double neighbors_found_energy_receive;
    double neighbors_found_energy_transfer;
    double consumed_energy;


public:
    explicit EnergyValue(QWidget *parent = 0);
    ~EnergyValue();

    QLabel* GetInitialEnergyLabel() const;
    QLabel* GetReceivePowerLabel() const;
    QLabel* GetTransferPowerLabel() const;
    QLabel* GetActivePowerLabel() const;
    QLabel* GetSleepPowerLabel() const;
    QSpinBox* GetInitialEnergySpinBox() const;
    QSpinBox* GetReceivePowerSpinBox() const;
    QSpinBox* GetTransferPowerSpinBox() const;
    QSpinBox* GetActivePowerSpinBox() const;
    QSpinBox* GetSleepPowerSpinBox() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetInitialEnergyLabel(QLabel *_initial_energy_label);
    void SetReceivePowerLabel(QLabel *_receive_power_label);
    void SetTransferPowerLabel(QLabel *_transfer_power_label);
    void SetActivePowerLabel(QLabel *_active_power_label);
    void SetSleepPowerLabel(QLabel *_sleep_power_label);
    void SetInitialEnergySpinBox(QSpinBox *_initial_energy_spin_box);
    void SetReceivePowerSpinBox(QSpinBox *_receive_power_spin_box);
    void SetTransferPowerSpinBox(QSpinBox *_transfer_power_spin_box);
    void SetActivePowerSpinBox(QSpinBox *_active_power_spin_box);
    void SetSleepPowerSpinBox(QSpinBox *_sleep_power_spin_box);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);

    double GetInitialEnergy() const;
    int GetReceivePower() const;
    int GetTransferPower() const;
    int GetActivePower() const;
    int GetSleepPower() const;

    void SetInitialEnergy(double _initial_energy);
    void SetReceivePower(int _receive_power);
    void SetTransferPower(int _transfer_power);
    void SetActivePower(int _active_power);
    void SetSleepPower(int _sleep_power);

    void SetParameters();


    double GetNeighborsFoundEnergyReceive() const;
    double GetNeighborsFoundEnergyTransfer() const;
    double GetConsumedEnergy() const;
    void SetNeighborsFoundEnergyReceive(double _energy);
    void SetNeighborsFoundEnergyTransfer(double _energy);
    void SetConsumedEnergy(double _energy);
    void CalculateNeighborsFoundEnergyReceive(double t_wait, double t_cca, double t_data, double t_ack);
    void CalculateNeighborsFoundEnergyTransfer(double t_wait, double t_cca, double t_data, double t_ack);
    void CalculateConsumedEnergy(double t_proc, double t_sleep);
};

#endif // ENERGYVALUE_H
