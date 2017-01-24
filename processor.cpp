#include "processor.h"
#include "ui_processor.h"

Processor::Processor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Processor)
{
    ui->setupUi(this);

    this->commands_number_label = ui->commands_number_label;
    this->operations_number_label = ui->operations_number_label;
    this->transition_time_label = ui->transition_time_label;
    this->transition_period_label = ui->transition_period_label;
    this->frequency_label = ui->frequency_label;

    this->commands_number_spin_box = ui->commands_number_spin_box;
    this->operations_number_spin_box = ui->operations_number_spin_box;
    this->transition_time_spin_box = ui->transition_time_spin_box;
    this->transition_period_spin_box = ui->transition_period_spin_box;
    this->frequency_spin_box = ui->frequency_spin_box;

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

Processor::~Processor()
{
    delete ui;
}

QLabel* Processor::GetCommandsNumberLabel() const
{
    return this->commands_number_label;
}

QLabel* Processor::GetOperationsNumberLabel() const
{
    return this->operations_number_label;
}

QLabel* Processor::GetTransitionTimeLabel() const
{
    return this->transition_time_label;
}

QLabel* Processor::GetTransitionPeriodLabel() const
{
    return this->transition_period_label;
}

QLabel* Processor::GetFrequencyLabel() const
{
    return this->frequency_label;
}

QSpinBox* Processor::GetCommandsNumberSpinBox() const
{
    return this->commands_number_spin_box;
}

QSpinBox* Processor::GetOperationsNumberSpinBox() const
{
    return this->operations_number_spin_box;
}

QSpinBox* Processor::GetTransitionTimeSpinBox() const
{
    return this->transition_time_spin_box;
}

QSpinBox* Processor::GetTransitionPeriodSpinBox() const
{
    return this->transition_period_spin_box;
}

QSpinBox* Processor::GetFrequencySpinBox() const
{
    return this->frequency_spin_box;
}

QDialogButtonBox* Processor::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* Processor::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* Processor::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* Processor::GetCancelButton() const
{
    return this->cancel_button;
}

void Processor::SetCommandsNumberLabel(QLabel *_commands_number_label)
{
    this->commands_number_label = _commands_number_label;
}

void Processor::SetOperationsNumberLabel(QLabel *_operations_number_label)
{
    this->operations_number_label = _operations_number_label;
}

void Processor::SetTransitionTimeLabel(QLabel *_transition_time_label)
{
    this->transition_time_label = _transition_time_label;
}

void Processor::SetTransitionPeriodLabel(QLabel *_transition_period_label)
{
    this->transition_period_label = _transition_period_label;
}

void Processor::SetFrequencyLabel(QLabel *_frequency_label)
{
    this->frequency_label = _frequency_label;
}

void Processor::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void Processor::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void Processor::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void Processor::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

int Processor::GetCommandsNumber() const
{
    return this->commands_number;
}

int Processor::GetOperationsNumber() const
{
    return this->operations_number;
}

int Processor::GetTransitionTime() const
{
    return this->transition_time;
}

int Processor::GetTransitionPeriod() const
{
    return this->transition_period;
}

int Processor::GetFrequency() const
{
    return this->frequency;
}

void Processor::SetCommandsNumber(int _commands_number)
{
    this->commands_number = _commands_number;
}

void Processor::SetOperationsNumber(int _operations_number)
{
    this->operations_number = _operations_number;
}

void Processor::SetTransitionTime(int _transition_time)
{
    this->transition_time = _transition_time;
}

void Processor::SetTransitionPeriod(int _transition_period)
{
    this->transition_period = _transition_period;
}

void Processor::SetFrequency(int _frequency)
{
    this->frequency = _frequency;
}

void Processor::RandomValue()
{
    int _transition_time, _transition_period, _frequency;
    int _operations_number, _commands_number;
    srand(time(0));
    _transition_time = this->transition_time_spin_box->minimum() + \
                        rand() % this->transition_time_spin_box->maximum() + 1;
    _transition_period = this->transition_period_spin_box->minimum() + \
                        rand() % this->transition_period_spin_box->maximum() + 1;
    _frequency = this->frequency_spin_box->minimum() + \
                        rand() % this->frequency_spin_box->maximum() + 1;
    _operations_number = this->operations_number_spin_box->minimum() + \
                        rand() % this->operations_number_spin_box->maximum() + 1;
    _commands_number = this->commands_number_spin_box->minimum() + \
                        rand() % this->commands_number_spin_box->maximum() + 1;
    this->transition_period_spin_box->setValue(_transition_period);
    this->transition_time_spin_box->setValue(_transition_time);
    this->frequency_spin_box->setValue(_frequency);
    this->operations_number_spin_box->setValue(_operations_number);
    this->commands_number_spin_box->setValue(_commands_number);
}

void Processor::SetParameters()
{
    this->transition_time = this->transition_time_spin_box->value();
    this->transition_period = this->transition_period_spin_box->value();
    this->frequency = this->frequency_spin_box->value();
    this->operations_number = this->operations_number_spin_box->value();
    this->commands_number = this->commands_number_spin_box->value();
}

void Processor::OKClicked()
{
    SetParameters();
    this->hide();
}

void Processor::CancelClicked()
{
    this->hide();
}
