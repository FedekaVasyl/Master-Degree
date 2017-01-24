#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <random>
#include <ctime>

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QPushButton>


enum Cloudiness {CLEARLY = 0, DARCLY, CLOUDY};

namespace Ui {
class Weather;
}

class Weather : public QDialog
{
    Q_OBJECT
public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();
private:
    Ui::Weather *ui;
    QLabel *cloudness_label;
    QLabel *temperature_label;
    QLabel *wind_speed_label;
    QLabel *wind_direction_label;
    QComboBox *cloudness_box;
    QSpinBox *temperature_spin_box;
    QSpinBox *wind_speed_spin_box;
    QSpinBox *wind_direction_spin_box;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;


    Cloudiness cloudiness;
    int temperature;
    int wind_speed;
    int wind_direction;


public:
    explicit Weather(QWidget *parent = 0);
    ~Weather();

    QLabel* GetCloudnessLabel() const;
    QLabel* GetTemperatureLabel() const;
    QLabel* GetWindSpeedLabel() const;
    QLabel* GetWindDirectionLabel() const;
    QComboBox* GetCloudnessBox() const;
    QSpinBox* GetTemperatureSpinBox() const;
    QSpinBox* GetWindSpeedSpinBox() const;
    QSpinBox* GetWindDirectionSpinBox() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetCloudnessLabel(QLabel *_cloudness_label);
    void SetTemperatureLabel(QLabel *_temperature_label);
    void SetWindSpeedLabel(QLabel *_wind_speed_label);
    void SetWindDirectionLabel(QLabel *_wind_direction_label);
    void SetCloudnessBox(QComboBox *_cloudness_box);
    void SetTemperatureSpinBox(QSpinBox *_temperature_spin_box);
    void SetWindSpeedSpinBox(QSpinBox *_wind_speed_spin_box);
    void SetWindDirectionSpinBox(QSpinBox *_wind_direction_spin_box);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);

    Cloudiness GetCloudiness() const;
    void SetCloudiness(Cloudiness _cloudiness);

    int GetTemperature() const;
    void SetTemperature(int _temperature);
    int GetWindSpeed() const;
    void SetWindSpeed(int _speed);
    int GetWindDirection() const;
    void SetWindDirection(int _direction);

    void SetParameters();

};

#endif // WEATHER_H
