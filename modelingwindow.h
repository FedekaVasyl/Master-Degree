#ifndef MODELINGWINDOW_H
#define MODELINGWINDOW_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;

namespace Ui {
class ModelingWindow;
}

class ModelingWindow : public QDialog
{
    Q_OBJECT

public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();

private:
    Ui::ModelingWindow *ui;
    QLabel *node_count_label;
    QLabel *sensitivity_limit_label;
    QLabel *height_label;
    QLabel *width_label;
    QLabel *x_label;
    QLabel *y_label;
    QLabel *routing_algorithm_label;
    QLabel *modeling_time_label;
    QSpinBox *node_count_spin_box;
    QSpinBox *sensitivity_limit_spin_box;
    QSpinBox *height_spin_box;
    QSpinBox *width_spin_box;
    QSpinBox *x_spin_box;
    QSpinBox *y_spin_box;
    QSpinBox *modeling_time_spin_box;
    QComboBox *routing_algorithm_combo_box;
    QRadioButton *free_observation_radio_button;
    QRadioButton *emergency_situation_radio_button;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    int node_count;
    int sensitivity_limit;
    int height;
    int width;
    int x;
    int y;
    int routing_algorithm;
    int modeling_time;
    bool free_observation;
    bool emergency_situation;


public:
    explicit ModelingWindow(QWidget *parent = 0);
    ~ModelingWindow();

    QLabel* GetNodeCountLabel() const;
    QLabel* GetSensitivityLimitLabel() const;
    QLabel* GetHeightLabel() const;
    QLabel* GetWidthLabel() const;
    QLabel* GetXLabel() const;
    QLabel* GetYLabel() const;
    QLabel* GetRoutingAlgorithmLabel() const;
    QLabel* GetModelingTimeLabel() const;
    QSpinBox* GetNodeCountSpinBox() const;
    QSpinBox* GetSensitivityLimitSpinBox() const;
    QSpinBox* GetHeightSpinBox() const;
    QSpinBox* GetWidthSpinBox() const;
    QSpinBox* GetXSpinBox() const;
    QSpinBox* GetYSpinBox() const;
    QSpinBox* GetModelingTimeSpinBox() const;
    QComboBox* GetRoutingAlgorithmComboBox() const;
    QRadioButton *GetFreeObservationRadioButton() const;
    QRadioButton *GetEmergencySituationRadioButton() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetNodeCountLabel(QLabel *_node_count_label);
    void SetSensitivityLimitLabel(QLabel *_sensitivity_limit_label);
    void SetHeightLabel(QLabel *_height_label);
    void SetWidthLabel(QLabel *_width_label);
    void SetXLabel(QLabel *_x_label);
    void SetYLabel(QLabel *_y_label);
    void SetRoutingAlgorithmLabel(QLabel *_routing_algorithm_label);
    void SetModelingTimeLabel(QLabel *_modeling_time_label);
    void SetNodeCountSpinBox(QSpinBox *_node_count_spin_box);
    void SetSensitivityLimitSpinBox(QSpinBox *_sensitivity_limit_spin_box);
    void SetHeigthSpinBox(QSpinBox *_height_spin_box);
    void SetWidthSpinBox(QSpinBox *_width_spin_box);
    void SetXSpinBox(QSpinBox *_x_spin_box);
    void SetYSpinBox(QSpinBox *_y_spin_box);
    void SetModelingTimeSpinBox(QSpinBox *_modeling_time_spin_box);
    void SetRoutingAlgorithmComboBox(QComboBox *_routing_algorithm_combo_box);
    void SetFreeObservationRadioButton(QRadioButton *_free_observation_radio_button);
    void SetEmergencySituationRadioButton(QRadioButton *_emergency_situation_radio_button);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);

    int GetNodeCount() const;
    int GetSensitivityLimit() const;
    int GetHeight() const;
    int GetWidth() const;
    int GetX() const;
    int GetY() const;
    int GetRoutingAlgorithm() const;
    int GetModelingTime() const;
    bool GetFreeObservation() const;
    bool GetEmergencySituation() const;
    void SetNodeCount(int _node_count);
    void SetSensitivityLimit(int _sensitivity_limit);
    void SetHeight(int _height);
    void SetWidth(int _width);
    void SetX(int _x);
    void SetY(int _y);
    void SetRoutingAlgorithm(int _routing_algorithm);
    void SetFreeObservation(bool _free_observation);
    void SetEmergencySituation(bool _emergency_situation);
    void SetModelingTime(int _modeling_time);

    void SetParameters();
};

#endif // MODELINGWINDOW_H
