#include "modelingwindow.h"
#include "ui_modelingwindow.h"

ModelingWindow::ModelingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelingWindow)
{
    ui->setupUi(this);

    this->node_count_label = ui->node_count_label;
    this->sensitivity_limit_label = ui->sensitivity_limit_label;
    this->height_label = ui->height_label;
    this->width_label = ui->width_label;
    this->x_label = ui->x_label;
    this->y_label = ui->y_label;
    this->routing_algorithm_label = ui->routing_algorithm_label;
    this->modeling_time_label = ui->modeling_time_label;
    this->node_count_spin_box = ui->node_count_spin_box;
    this->sensitivity_limit_spin_box = ui->sensitivity_limit_spin_box;
    this->height_spin_box = ui->height_spin_box;
    this->width_spin_box = ui->width_spin_box;
    this->x_spin_box = ui->x_spin_box;
    this->y_spin_box = ui->y_spin_box;
    this->modeling_time_spin_box = ui->modeling_time_spin_box;
    this->routing_algorithm_combo_box = ui->routing_algorithm_combo_box;
    this->free_observation_radio_button = ui->free_observation_radio_button;
    this->emergency_situation_radio_button = ui->emergency_situation_radio_button;

    this->dialog_button_box = ui->dialog_button_box;
    this->random_button = ui->random_button;
    this->ok_button = ui->dialog_button_box->button(QDialogButtonBox::Ok);
    this->cancel_button = ui->dialog_button_box->button(QDialogButtonBox::Cancel);

    this->routing_algorithm_combo_box->addItem("Directed Diffusions");
    this->routing_algorithm_combo_box->addItem("Disjoint Paths");
    this->routing_algorithm_combo_box->addItem("Geographic Adaptive Fidelity");
    this->routing_algorithm_combo_box->addItem("Two-Tier Data Dissemination");

    QObject::connect(this->random_button,SIGNAL(clicked(bool)),\
                     this,SLOT(RandomValue()));
    QObject::connect(this->ok_button,SIGNAL(clicked(bool)),\
                     this,SLOT(OKClicked()));
    QObject::connect(this->cancel_button,SIGNAL(clicked(bool)),\
                     this,SLOT(CancelClicked()));
    SetParameters();
}

ModelingWindow::~ModelingWindow()
{
    delete ui;
}

QLabel* ModelingWindow::GetNodeCountLabel() const
{
    return this->node_count_label;
}

QLabel* ModelingWindow::GetSensitivityLimitLabel() const
{
    return this->sensitivity_limit_label;
}

QLabel* ModelingWindow::GetHeightLabel() const
{
    return this->height_label;
}

QLabel* ModelingWindow::GetWidthLabel() const
{
    return this->width_label;
}

QLabel* ModelingWindow::GetXLabel() const
{
    return this->x_label;
}

QLabel* ModelingWindow::GetYLabel() const
{
    return this->y_label;
}

QLabel* ModelingWindow::GetRoutingAlgorithmLabel() const
{
    return this->routing_algorithm_label;
}

QLabel* ModelingWindow::GetModelingTimeLabel() const
{
    return this->modeling_time_label;
}

QSpinBox* ModelingWindow::GetNodeCountSpinBox() const
{
    return this->node_count_spin_box;
}

QSpinBox* ModelingWindow::GetSensitivityLimitSpinBox() const
{
    return this->sensitivity_limit_spin_box;
}

QSpinBox* ModelingWindow::GetHeightSpinBox() const
{
    return this->height_spin_box;
}

QSpinBox* ModelingWindow::GetWidthSpinBox() const
{
    return this->width_spin_box;
}

QSpinBox* ModelingWindow::GetXSpinBox() const
{
    return this->x_spin_box;
}

QSpinBox* ModelingWindow::GetYSpinBox() const
{
    return this->y_spin_box;
}

QSpinBox* ModelingWindow::GetModelingTimeSpinBox() const
{
    return this->modeling_time_spin_box;
}

QComboBox* ModelingWindow::GetRoutingAlgorithmComboBox() const
{
    return this->routing_algorithm_combo_box;
}

QRadioButton* ModelingWindow::GetFreeObservationRadioButton() const
{
    return this->free_observation_radio_button;
}

QRadioButton* ModelingWindow::GetEmergencySituationRadioButton() const
{
    return this->emergency_situation_radio_button;
}

QDialogButtonBox* ModelingWindow::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* ModelingWindow::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* ModelingWindow::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* ModelingWindow::GetCancelButton() const
{
    return this->cancel_button;
}

void ModelingWindow::SetNodeCountLabel(QLabel *_node_count_label)
{
    this->node_count_label = _node_count_label;
}

void ModelingWindow::SetSensitivityLimitLabel(QLabel *_sensitivity_limit_label)
{
    this->sensitivity_limit_label = _sensitivity_limit_label;
}

void ModelingWindow::SetHeightLabel(QLabel *_height_label)
{
    this->height_label = _height_label;
}

void ModelingWindow::SetWidthLabel(QLabel *_width_label)
{
    this->width_label = _width_label;
}

void ModelingWindow::SetXLabel(QLabel *_x_label)
{
    this->x_label = _x_label;
}

void ModelingWindow::SetYLabel(QLabel *_y_label)
{
    this->y_label = _y_label;
}

void ModelingWindow::SetRoutingAlgorithmLabel(QLabel *_routing_algorithm_label)
{
    this->routing_algorithm_label = _routing_algorithm_label;
}

void ModelingWindow::SetModelingTimeLabel(QLabel *_modeling_time_label)
{
    this->modeling_time_label = _modeling_time_label;
}

void ModelingWindow::SetNodeCountSpinBox(QSpinBox *_node_count_spin_box)
{
    this->node_count_spin_box = _node_count_spin_box;
}

void ModelingWindow::SetSensitivityLimitSpinBox(QSpinBox *_sensitivity_limit_spin_box)
{
    this->sensitivity_limit_spin_box = _sensitivity_limit_spin_box;
}

void ModelingWindow::SetHeigthSpinBox(QSpinBox *_height_spin_box)
{
    this->height_spin_box = _height_spin_box;
}

void ModelingWindow::SetWidthSpinBox(QSpinBox *_width_spin_box)
{
    this->width_spin_box = _width_spin_box;
}

void ModelingWindow::SetXSpinBox(QSpinBox *_x_spin_box)
{
    this->x_spin_box = _x_spin_box;
}

void ModelingWindow::SetYSpinBox(QSpinBox *_y_spin_box)
{
    this->y_spin_box = _y_spin_box;
}

void ModelingWindow::SetModelingTimeSpinBox(QSpinBox *_modeling_time_spin_box)
{
    this->modeling_time_spin_box = _modeling_time_spin_box;
}

void ModelingWindow::SetRoutingAlgorithmComboBox(QComboBox *_routing_algorithm_combo_box)
{
    this->routing_algorithm_combo_box = _routing_algorithm_combo_box;
}

void ModelingWindow::SetFreeObservationRadioButton(QRadioButton *_free_observation_radio_button)
{
    this->free_observation_radio_button = _free_observation_radio_button;
}

void ModelingWindow::SetEmergencySituationRadioButton(QRadioButton *_emergency_situation_radio_button)
{
    this->emergency_situation_radio_button = _emergency_situation_radio_button;
}

void ModelingWindow::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void ModelingWindow::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void ModelingWindow::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void ModelingWindow::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

int ModelingWindow::GetNodeCount() const
{
    return this->node_count;
}

int ModelingWindow::GetSensitivityLimit() const
{
    return this->sensitivity_limit;
}

int ModelingWindow::GetHeight() const
{
    return this->height;
}

int ModelingWindow::GetWidth() const
{
    return this->width;
}

int ModelingWindow::GetX() const
{
    return this->x;
}

int ModelingWindow::GetY() const
{
    return this->y;
}

int ModelingWindow::GetRoutingAlgorithm() const
{
    return this->routing_algorithm;
}

int ModelingWindow::GetModelingTime() const
{
    return this->modeling_time;
}

bool ModelingWindow::GetFreeObservation() const
{
    return this->free_observation;
}

bool ModelingWindow::GetEmergencySituation() const
{
    return this->emergency_situation;
}

void ModelingWindow::SetNodeCount(int _node_count)
{
    this->node_count = _node_count;
}

void ModelingWindow::SetSensitivityLimit(int _sensitivity_limit)
{
    this->sensitivity_limit = _sensitivity_limit;
}

void ModelingWindow::SetHeight(int _height)
{
    this->height = _height;
}

void ModelingWindow::SetWidth(int _width)
{
    this->width = _width;
}

void ModelingWindow::SetX(int _x)
{
    this->x = _x;
}

void ModelingWindow::SetY(int _y)
{
    this->y = _y;
}

void ModelingWindow::SetRoutingAlgorithm(int _routing_algorithm)
{
    this->routing_algorithm = _routing_algorithm;
}

void ModelingWindow::SetFreeObservation(bool _free_observation)
{
    this->free_observation = _free_observation;
}

void ModelingWindow::SetEmergencySituation(bool _emergency_situation)
{
    this->emergency_situation = _emergency_situation;
}

void ModelingWindow::SetModelingTime(int _modeling_time)
{
    this->modeling_time = _modeling_time;
}

void ModelingWindow::RandomValue()
{
    int _node_count;
    int _sensitivity_limit;
    int _height;
    int _width;
    int _x;
    int _y;
    int _routing;
    int _time;
    srand(time(0));
    _node_count = this->node_count_spin_box->minimum() + \
                rand() % this->node_count_spin_box->maximum() + 1;
    _sensitivity_limit = this->sensitivity_limit_spin_box->minimum() + \
                rand() % this->sensitivity_limit_spin_box->maximum() + 1;
    _height = this->height_spin_box->minimum() + \
                rand() % this->height_spin_box->maximum() + 1;
    _width = this->width_spin_box->minimum() + \
                rand() % this->width_spin_box->maximum() + 1;
    _x = this->x_spin_box->minimum() + \
                rand() % this->x_spin_box->maximum() + 1;
    _y = this->y_spin_box->minimum() + \
                rand() % this->y_spin_box->maximum() + 1;
    _time = this->modeling_time_spin_box->minimum() + \
                rand() % this->modeling_time_spin_box->maximum() + 1;
    _routing = rand() % 4;
    this->node_count_spin_box->setValue(_node_count);
    this->sensitivity_limit_spin_box->setValue(_sensitivity_limit);
    this->height_spin_box->setValue(_height);
    this->width_spin_box->setValue(_width);
    this->x_spin_box->setValue(_x);
    this->y_spin_box->setValue(_y);
    this->routing_algorithm_combo_box->setCurrentIndex(_routing);
    this->modeling_time_spin_box->setValue(_time);
}

void ModelingWindow::SetParameters()
{
    this->node_count = this->node_count_spin_box->value();
    this->sensitivity_limit = this->sensitivity_limit_spin_box->value();
    this->height = this->height_spin_box->value();
    this->width = this->width_spin_box->value();
    this->x = this->x_spin_box->value();
    this->y = this->y_spin_box->value();
    this->routing_algorithm = this->routing_algorithm_combo_box->currentIndex();
    this->free_observation = this->free_observation_radio_button->isChecked();
    this->emergency_situation = this->emergency_situation_radio_button->isChecked();
    this->modeling_time = this->modeling_time_spin_box->value();
}

void ModelingWindow::OKClicked()
{
    SetParameters();
    this->hide();
}

void ModelingWindow::CancelClicked()
{
    this->hide();
}
