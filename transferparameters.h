#ifndef TRANSFERPARAMETERS_H
#define TRANSFERPARAMETERS_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;

namespace Ui {
class TransferParameters;
}

class TransferParameters : public QDialog
{
    Q_OBJECT
public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();
private:
    Ui::TransferParameters *ui;

    QLabel *packet_length_label;
    QLabel *error_probability_label;
    QLabel *retransmissions_number_label;
    QLabel *delay_factor_label;
    QLabel *transfer_speed_label;
    QLabel *service_length_label;
    QLabel *transfer_radius_label;
    QSpinBox *packet_length_spin_box;
    QSpinBox *error_probability_spin_box;
    QSpinBox *retransmissions_number_spin_box;
    QSpinBox *delay_factor_spin_box;
    QSpinBox *transfer_speed_spin_box;
    QSpinBox *service_length_spin_box;
    QSpinBox *transfer_radius_spin_box;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    int packet_length;
    int error_probability;
    int retransmissions_number;
    int delay_factor;
    int transfer_speed;
    int service_length;
    int transfer_radius;


    double retransmissions_factor;
    double t_wait;
    double t_cca;
    double t_data;
    double t_ack;
    double t_proc;
    double t_sleep;

public:
    explicit TransferParameters(QWidget *parent = 0);
    ~TransferParameters();

    QLabel* GetPacketLengthLabel() const;
    QLabel* GetErrorProbabilityLabel() const;
    QLabel* GetRetransmissionsNumberLabel() const;
    QLabel* GetDelayFactorLabel() const;
    QLabel* GetTransferSpeedLabel() const;
    QLabel* GetServiceLengthLabel() const;
    QLabel* GetTransferRadiusLabel() const;
    QSpinBox* GetPacketLengthSpinBox() const;
    QSpinBox* GetErrorProbabilitySpinBox() const;
    QSpinBox* GetRetransmissionsNumberSpinBox() const;
    QSpinBox* GetDelayFactorSpinBox() const;
    QSpinBox* GetTransferSpeedSpinBox() const;
    QSpinBox* GetServiceLengthSpinBox() const;
    QSpinBox* GetTransferRadiusSpinBox() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetPacketLengthLabel(QLabel *_packet_length_label);
    void SetErrorProbabilityLabel(QLabel *_error_probability_label);
    void SetRetransmissionsNumberLabel(QLabel *_retransmissions_number_label);
    void SetDelayFactorLabel(QLabel *_delay_factor_label);
    void SetTransferSpeedLabel(QLabel *_transfer_speed_label);
    void SetServiceLengthLabel(QLabel *_service_length_label);
    void SetTransferRadiusLabel(QLabel *_transfer_radius_label);
    void SetPacketLengthSpinBox(QSpinBox *_packet_length_spin_box);
    void SetErrorProbabilitySpinBox(QSpinBox *_error_probability_spin_box);
    void SetRetransmissionsNumberSpinBox(QSpinBox *_retransmissions_number_spin_box);
    void SetDelayFactorSpinBox(QSpinBox *_delay_factor_spin_box);
    void SetTransferSpeedSpinBox(QSpinBox *_transfer_speed_spin_box);
    void SetServiceLengthSpinBox(QSpinBox *_service_length_spin_box);
    void SetTransferRadiusSpinBox(QSpinBox *_transfer_radius_spin_box);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);

    int GetPacketLength() const;
    int GetErrorProbability() const;
    int GetRetransmissionsNumber() const;
    int GetDelayFactor() const;
    int GetTransferSpeed() const;
    int GetServiceLength() const;
    int GetTransferRadius() const;

    void SetPacketLength(int _packet_length);
    void SetErrorProbability(int _error_probability);
    void SetRetransmissionsNumber(int _retransmissions_number);
    void SetDelayFactor(int _delay_factor);
    void SetTransferSpeed(int _transfer_Speed);
    void SetServiceLength(int _service_length);
    void SetTransferRadius(int _transfer_radius);

    void SetParameters();



    double GetRetransmissionsFactor() const;
    void SetRetransmissionsFactor(double _factor);
    void CalculateRetransmissionsFactor();

    double GetTWait() const;
    double GetTCCA() const;
    double GetTData() const;
    double GetTACK() const;
    double GetTProc() const;
    double GetTSleep() const;

    void SetTWait(double _t);
    void SetTCCA(double _t);
    void SetTData(double _t);
    void SetTACK(double _t);
    void SetTProc(double _t);
    void SetTSleep(double _t);

    void CalculateTWait();
    void CalculateTCCA();
    void CalculateTData();
    void CalculateTACK();
    void CalculateTProc(double t, int M, int C, int f);
    void CalculateTSleep(double t);


};

#endif // TRANSFERPARAMETERS_H
