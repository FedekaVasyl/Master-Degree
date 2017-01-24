#include "transferparameters.h"
#include "ui_transferparameters.h"

TransferParameters::TransferParameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferParameters)
{
    ui->setupUi(this);

    this->packet_length_label = ui->packet_length_label;
    this->error_probability_label = ui->error_probability_label;
    this->retransmissions_number_label = ui->retransmissions_number_label;
    this->delay_factor_label = ui->delay_factor_label;
    this->transfer_speed_label = ui->transfer_speed_label;
    this->service_length_label = ui->service_length_label;
    this->transfer_radius_label = ui->transfer_radius_label;
    this->packet_length_spin_box = ui->packet_length_spin_box;
    this->error_probability_spin_box = ui->error_probability_spin_box;
    this->retransmissions_number_spin_box = ui->retransmissions_number_spin_box;
    this->delay_factor_spin_box = ui->delay_factor_spin_box;
    this->transfer_speed_spin_box = ui->transfer_speed_spin_box;
    this->service_length_spin_box = ui->service_length_spin_box;
    this->transfer_radius_spin_box = ui->transfer_radius_spin_box;

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

TransferParameters::~TransferParameters()
{
    delete ui;
}

QLabel* TransferParameters::GetPacketLengthLabel() const
{
    return this->packet_length_label;
}

QLabel* TransferParameters::GetErrorProbabilityLabel() const
{
    return this->error_probability_label;
}

QLabel* TransferParameters::GetRetransmissionsNumberLabel() const
{
    return this->retransmissions_number_label;
}

QLabel* TransferParameters::GetDelayFactorLabel() const
{
    return this->delay_factor_label;
}

QLabel* TransferParameters::GetTransferSpeedLabel() const
{
    return this->transfer_speed_label;
}

QLabel* TransferParameters::GetServiceLengthLabel() const
{
    return this->service_length_label;
}

QLabel* TransferParameters::GetTransferRadiusLabel() const
{
    return this->transfer_radius_label;
}

QSpinBox* TransferParameters::GetPacketLengthSpinBox() const
{
    return this->packet_length_spin_box;
}

QSpinBox* TransferParameters::GetErrorProbabilitySpinBox() const
{
    return this->error_probability_spin_box;
}

QSpinBox* TransferParameters::GetRetransmissionsNumberSpinBox() const
{
    return this->retransmissions_number_spin_box;
}

QSpinBox* TransferParameters::GetDelayFactorSpinBox() const
{
    return this->delay_factor_spin_box;
}

QSpinBox* TransferParameters::GetTransferSpeedSpinBox() const
{
    return this->transfer_speed_spin_box;
}

QSpinBox* TransferParameters::GetServiceLengthSpinBox() const
{
    return this->service_length_spin_box;
}

QSpinBox* TransferParameters::GetTransferRadiusSpinBox() const
{
    return this->transfer_radius_spin_box;
}

QDialogButtonBox* TransferParameters::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* TransferParameters::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* TransferParameters::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* TransferParameters::GetCancelButton() const
{
    return this->cancel_button;
}

void TransferParameters::SetPacketLengthLabel(QLabel *_packet_length_label)
{
    this->packet_length_label = _packet_length_label;
}

void TransferParameters::SetErrorProbabilityLabel(QLabel *_error_probability_label)
{
    this->error_probability_label = _error_probability_label;
}

void TransferParameters::SetRetransmissionsNumberLabel(QLabel *_retransmissions_number_label)
{
    this->retransmissions_number_label = _retransmissions_number_label;
}

void TransferParameters::SetDelayFactorLabel(QLabel *_delay_factor_label)
{
    this->delay_factor_label = _delay_factor_label;
}

void TransferParameters::SetTransferSpeedLabel(QLabel *_transfer_speed_label)
{
    this->transfer_speed_label = _transfer_speed_label;
}

void TransferParameters::SetServiceLengthLabel(QLabel *_service_length_label)
{
    this->service_length_label = _service_length_label;
}

void TransferParameters::SetTransferRadiusLabel(QLabel *_transfer_radius_label)
{
    this->transfer_radius_label = _transfer_radius_label;
}

void TransferParameters::SetPacketLengthSpinBox(QSpinBox *_packet_length_spin_box)
{
    this->packet_length_spin_box = _packet_length_spin_box;
}

void TransferParameters::SetErrorProbabilitySpinBox(QSpinBox *_error_probability_spin_box)
{
    this->error_probability_spin_box = _error_probability_spin_box;
}

void TransferParameters::SetRetransmissionsNumberSpinBox(QSpinBox *_retransmissions_number_spin_box)
{
    this->retransmissions_number_spin_box = _retransmissions_number_spin_box;
}

void TransferParameters::SetDelayFactorSpinBox(QSpinBox *_delay_factor_spin_box)
{
    this->delay_factor_spin_box = _delay_factor_spin_box;
}

void TransferParameters::SetTransferSpeedSpinBox(QSpinBox *_transfer_speed_spin_box)
{
    this->transfer_speed_spin_box = _transfer_speed_spin_box;
}

void TransferParameters::SetServiceLengthSpinBox(QSpinBox *_service_length_spin_box)
{
    this->service_length_spin_box = _service_length_spin_box;
}

void TransferParameters::SetTransferRadiusSpinBox(QSpinBox *_transfer_radius_spin_box)
{
    this->transfer_radius_spin_box = _transfer_radius_spin_box;
}

void TransferParameters::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void TransferParameters::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void TransferParameters::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void TransferParameters::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

int TransferParameters::GetPacketLength() const
{
    return this->packet_length;
}

int TransferParameters::GetErrorProbability() const
{
    return this->error_probability;
}

int TransferParameters::GetRetransmissionsNumber() const
{
    return this->retransmissions_number;
}

int TransferParameters::GetDelayFactor() const
{
    return this->delay_factor;
}

int TransferParameters::GetTransferSpeed() const
{
    return this->transfer_speed;
}

int TransferParameters::GetServiceLength() const
{
    return this->service_length;
}

int TransferParameters::GetTransferRadius() const
{
    return this->transfer_radius;
}

double TransferParameters::GetRetransmissionsFactor() const
{
    return this->retransmissions_factor;
}

double TransferParameters::GetTACK() const
{
    return this->t_ack;
}

double TransferParameters::GetTCCA() const
{
    return this->t_cca;
}

double TransferParameters::GetTData() const
{
    return this->t_data;
}

double TransferParameters::GetTWait() const
{
    return this->t_wait;
}

double TransferParameters::GetTProc() const
{
    return this->t_proc;
}

double TransferParameters::GetTSleep() const
{
    return this->t_sleep;
}

void TransferParameters::SetPacketLength(int _packet_length)
{
    this->packet_length = _packet_length;
}

void TransferParameters::SetErrorProbability(int _error_probability)
{
    this->error_probability = _error_probability;
}

void TransferParameters::SetRetransmissionsNumber(int _retransmissions_number)
{
    this->retransmissions_number = _retransmissions_number;
}

void TransferParameters::SetDelayFactor(int _delay_factor)
{
    this->delay_factor = _delay_factor;
}

void TransferParameters::SetTransferSpeed(int _transfer_speed)
{
    this->transfer_speed = _transfer_speed;
}

void TransferParameters::SetServiceLength(int _service_length)
{
    this->service_length = _service_length;
}

void TransferParameters::SetTransferRadius(int _transfer_radius)
{
    this->transfer_radius = _transfer_radius;
}

void TransferParameters::SetRetransmissionsFactor(double _factor)
{
    this->retransmissions_factor = _factor;
}

void TransferParameters::SetTACK(double _t)
{
    this->t_ack = _t;
}

void TransferParameters::SetTCCA(double _t)
{
    this->t_cca = _t;
}

void TransferParameters::SetTData(double _t)
{
    this->t_data = _t;
}

void TransferParameters::SetTWait(double _t)
{
    this->t_wait = _t;
}

void TransferParameters::SetTProc(double _t)
{
    this->t_proc = _t;
}

void TransferParameters::SetTSleep(double _t)
{
    this->t_sleep = _t;
}

void TransferParameters::RandomValue()
{
    int _packet_length;
    int _error_probability;
    int _retransmissions_number;
    int _delay_factor;
    int _transfer_speed;
    int _service_length;
    int _transfer_radius;
    srand(time(0));
    _packet_length = this->packet_length_spin_box->minimum() + \
                    rand() % this->packet_length_spin_box->maximum() + 1;
    _error_probability = this->error_probability_spin_box->minimum() + \
                    rand() % this->error_probability_spin_box->maximum() + 1;
    _retransmissions_number = this->retransmissions_number_spin_box->minimum() + \
                    rand() % this->retransmissions_number_spin_box->maximum() + 1;
    _delay_factor = this->delay_factor_spin_box->minimum() + \
                    rand() % this->delay_factor_spin_box->maximum() + 1;
    _transfer_speed = this->transfer_speed_spin_box->minimum() + \
                    rand() % this->transfer_speed_spin_box->maximum() + 1;
    _service_length = this->service_length_spin_box->minimum() + \
                    rand() % this->service_length_spin_box->maximum() + 1;
    _transfer_radius = this->transfer_radius_spin_box->minimum() + \
                    rand() % this->transfer_radius_spin_box->maximum() + 1;
    this->packet_length_spin_box->setValue(_packet_length);
    this->error_probability_spin_box->setValue(_error_probability);
    this->retransmissions_number_spin_box->setValue(_retransmissions_number);
    this->delay_factor_spin_box->setValue(_delay_factor);
    this->transfer_speed_spin_box->setValue(_service_length);
    this->service_length_spin_box->setValue(_service_length);
    this->transfer_radius_spin_box->setValue(_transfer_radius);
}

void TransferParameters::SetParameters()
{
    this->packet_length = this->packet_length_spin_box->value();
    this->error_probability = this->error_probability_spin_box->value();
    this->retransmissions_number = this->retransmissions_number_spin_box->value();
    this->delay_factor = this->delay_factor_spin_box->value();
    this->transfer_speed = this->transfer_speed_spin_box->value();
    this->service_length = this->service_length_spin_box->value();
    this->transfer_radius = this->transfer_radius_spin_box->value();
    this->CalculateRetransmissionsFactor();
    this->CalculateTACK();
    this->CalculateTCCA();
    this->CalculateTData();
    this->CalculateTWait();
}

void TransferParameters::OKClicked()
{
    SetParameters();
    this->hide();
}

void TransferParameters::CancelClicked()
{
    this->hide();
}


void TransferParameters::CalculateRetransmissionsFactor()
{
    double p, _factor = 0;
    int N, i;
    p = double (this->GetErrorProbability()) / 100.0;
    N = this->GetRetransmissionsNumber();
    for(i = 1; i <= N - 1; i++) {
        _factor += i * pow(p, i - 1);
    }
    _factor *= 1 - p;
    _factor += N * pow(p, N - 1);
    this->SetRetransmissionsFactor(_factor);
}

void TransferParameters::CalculateTACK()
{
    double v = double(this->GetTransferSpeed()) * 1024.0;
    double packet = 11.0 * 8.0;
    double t = packet / v;
    t *= this->GetRetransmissionsFactor();
    this->SetTACK(t);
}

void TransferParameters::CalculateTCCA()
{
    double t = 0.000128;
    t *= this->GetRetransmissionsFactor();
    this->SetTCCA(t);
}

void TransferParameters::CalculateTData()
{
    double packet = double(this->GetPacketLength()) + double(this->GetServiceLength());
    double v = double(this->GetTransferSpeed()) * 1024.0;
    double t;
    packet *= 8.0;
    t = packet / v;
    t *= this->GetRetransmissionsFactor();
    this->SetTData(t);
}

void TransferParameters::CalculateTWait()
{
    int BE = this->GetDelayFactor();
    int max = pow(2,BE);
    int R;
    double t = 0.00032;
    srand(time(0));
    R = rand() % max;
    t *= R;
    t *= this->GetRetransmissionsFactor();
    this->SetTWait(t);
}

void TransferParameters::CalculateTProc(double t, int M, int C, int f)
{
    double _t = t / 1000.0 + (double(M) * double(C)) / (double(f) * 1000000.0);
    this->SetTProc(_t);
}

void TransferParameters::CalculateTSleep(double t)
{
    double _t = t - (this->GetTProc() + \
                     this->GetTWait() + \
                     this->GetTCCA() + \
                     this->GetTACK() + \
                     this->GetTData());
    if(_t < 0) {
        _t = 0;
    }
    this->SetTSleep(_t);
}
