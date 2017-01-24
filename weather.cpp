#include "weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    this->cloudness_label = ui->cloudness_label;
    this->temperature_label = ui->temperature_label;
    this->wind_direction_label = ui->wind_direction_label;
    this->wind_speed_label = ui->wind_speed_label;
    this->cloudness_box = ui->cloudness_box;
    this->temperature_spin_box = ui->temperature_spin_box;
    this->wind_direction_spin_box = ui->wind_direction_spin_box;
    this->wind_speed_spin_box = ui->wind_speed_spin_box;
    this->dialog_button_box = ui->dialog_button_box;
    this->random_button = ui->random_button;
    this->ok_button = ui->dialog_button_box->button(QDialogButtonBox::Ok);
    this->cancel_button = ui->dialog_button_box->button(QDialogButtonBox::Cancel);

    this->cloudness_box->addItem("Відсутня (ясно)");
    this->cloudness_box->addItem("Середня (напівясно)");
    this->cloudness_box->addItem("Суцільна (хмарно)");

    QObject::connect(this->random_button,SIGNAL(clicked(bool)),\
                     this,SLOT(RandomValue()));
    QObject::connect(this->ok_button,SIGNAL(clicked(bool)),\
                     this,SLOT(OKClicked()));
    QObject::connect(this->cancel_button,SIGNAL(clicked(bool)),\
                     this,SLOT(CancelClicked()));
    SetParameters();
}

Weather::~Weather()
{
    delete ui;
}

Cloudiness Weather::GetCloudiness() const
{
    return this->cloudiness;
}

void Weather::SetCloudiness(Cloudiness _cloudiness)
{
    this->cloudiness = _cloudiness;
}

int Weather::GetTemperature() const
{
    return this->temperature;
}

void Weather::SetTemperature(int _temperature)
{
    this->temperature = _temperature;
}

/*int Weather::GetTime() const
{
    return this->time;
}

void Weather::SetTime(int _time)
{
    this->time = _time;
}*/

int Weather::GetWindDirection() const
{
    return this->wind_direction;
}

void Weather::SetWindDirection(int _direction)
{
    this->wind_direction = _direction;
}

int Weather::GetWindSpeed() const
{
    return this->wind_speed;
}

void Weather::SetWindSpeed(int _speed)
{
    this->wind_speed = _speed;
}

QLabel* Weather::GetCloudnessLabel() const
{
    return this->cloudness_label;
}

QLabel* Weather::GetTemperatureLabel() const
{
    return this->temperature_label;
}

QLabel* Weather::GetWindSpeedLabel() const
{
    return this->wind_speed_label;
}

QLabel* Weather::GetWindDirectionLabel() const
{
    return this->wind_direction_label;
}

QComboBox* Weather::GetCloudnessBox() const
{
    return this->cloudness_box;
}

QSpinBox* Weather::GetTemperatureSpinBox() const
{
    return this->temperature_spin_box;
}

QSpinBox* Weather::GetWindSpeedSpinBox() const
{
    return this->wind_speed_spin_box;
}

QSpinBox* Weather::GetWindDirectionSpinBox() const
{
    return this->wind_direction_spin_box;
}

QDialogButtonBox* Weather::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* Weather::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* Weather::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* Weather::GetCancelButton() const
{
    return this->cancel_button;
}

void Weather::SetCloudnessLabel(QLabel *_cloudness_label)
{
    this->cloudness_label = _cloudness_label;
}

void Weather::SetTemperatureLabel(QLabel *_temperature_label)
{
    this->temperature_label = _temperature_label;
}

void Weather::SetWindSpeedLabel(QLabel *_wind_speed_label)
{
    this->wind_speed_label = _wind_speed_label;
}

void Weather::SetWindDirectionLabel(QLabel *_wind_direction_label)
{
    this->wind_direction_label = _wind_direction_label;
}

void Weather::SetCloudnessBox(QComboBox *_cloudness_box)
{
    this->cloudness_box = _cloudness_box;
}

void Weather::SetTemperatureSpinBox(QSpinBox *_temperature_spin_box)
{
    this->temperature_spin_box = _temperature_spin_box;
}

void Weather::SetWindSpeedSpinBox(QSpinBox *_wind_speed_spin_box)
{
    this->wind_speed_spin_box = _wind_speed_spin_box;
}

void Weather::SetWindDirectionSpinBox(QSpinBox *_wind_direction_spin_box)
{
    this->wind_direction_spin_box = _wind_direction_spin_box;
}

void Weather::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void Weather::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void Weather::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void Weather::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

void Weather::RandomValue()
{
    int cloud, speed, direction, t;
    srand(time(0));
    cloud = rand() % 3;
    speed = rand() % 11;
    direction = rand() % 361;
    t = (rand() % 61) - 20;
    this->cloudness_box->setCurrentIndex(cloud);
    this->wind_direction_spin_box->setValue(direction);
    this->wind_speed_spin_box->setValue(speed);
    this->temperature_spin_box->setValue(t);
}

void Weather::SetParameters()
{
    this->cloudiness = Cloudiness(this->cloudness_box->currentIndex());
    this->wind_speed = this->wind_speed_spin_box->value();
    this->wind_direction = this->wind_direction_spin_box->value();
    this->temperature = this->temperature_spin_box->value();
}

void Weather::OKClicked()
{
    SetParameters();
    this->hide();
}

void Weather::CancelClicked()
{
    this->hide();
}
