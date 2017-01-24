#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QCheckBox>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QDialog
{
    Q_OBJECT
public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();
private:
    Ui::ImageWindow *ui;
    QLabel *scale_label;
    QLabel *diameter_node_label;
    QSpinBox *scale_spin_box;
    QSpinBox *diameter_node_spin_box;
    QCheckBox *sensor_scope_check_box;
    QCheckBox *uncovered_sensor_check_box;
    QCheckBox *dead_sensor_check_box;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    int diameter_node;
    int scale;
    bool sensor_scope;
    bool uncovered_sensor;
    bool dead_sensor;



public:
    explicit ImageWindow(QWidget *parent = 0);
    ~ImageWindow();

    QLabel *GetScaleLabel() const;
    QLabel *GetDiameterNodeLabel() const;
    QSpinBox *GetScaleSpinBox() const;
    QSpinBox *GetDiameterNodeSpinBox() const;
    QCheckBox *GetSensorScopeCheckBox() const;
    QCheckBox *GetUncoveredSensorCheckBox() const;
    QCheckBox *GetDeadSensorCheckBox() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetScaleLabel(QLabel *_scale_label);
    void SetDiameterNodeLabel(QLabel *_diameter_node_label);
    void SetScaleSpinBox(QSpinBox *_scale_spin_box);
    void SetDiameterNodeSpinBox(QSpinBox *_diameter_node_spin_box);
    void SetSensorScopeCheckBox(QCheckBox *_sensor_scope_check_box);
    void SetUncoveredNodeCheckBox(QCheckBox *_uncovered_sensor_check_box);
    void SetDeadSensorCheckBox(QCheckBox *_dead_sensor_check_box);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);

    int GetScale() const;
    int GetDiameterNode() const;
    bool GetSensorScope() const;
    bool GetUncoveredSensor() const;
    bool GetDeadSensor() const;

    void SetScale(int _scale);
    void SetDiameterNode(int _diameter_node);
    void SetSensorScope(bool _sensor_scope);
    void SetUncoveredNode(bool _uncovered_sensor);
    void SetDeadSensor(bool _dead_sensor);

    void SetParameters();

};

#endif // IMAGEWINDOW_H
