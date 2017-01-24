#include "imagewindow.h"
#include "ui_imagewindow.h"

ImageWindow::ImageWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);

    this->scale_label = ui->scale_label;
    this->diameter_node_label = ui->diameter_node_label;
    this->scale_spin_box = ui->scale_spin_box;
    this->diameter_node_spin_box = ui->diameter_node_spin_box;
    this->sensor_scope_check_box = ui->sensor_scope_check_box;
    this->uncovered_sensor_check_box = ui->uncovered_node_check_box;
    this->dead_sensor_check_box = ui->dead_node_check_box;

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

ImageWindow::~ImageWindow()
{
    delete ui;
}

QLabel* ImageWindow::GetScaleLabel() const
{
    return this->scale_label;
}

QLabel* ImageWindow::GetDiameterNodeLabel() const
{
    return this->diameter_node_label;
}

QSpinBox* ImageWindow::GetScaleSpinBox() const
{
    return this->scale_spin_box;
}

QSpinBox* ImageWindow::GetDiameterNodeSpinBox() const
{
    return this->diameter_node_spin_box;
}

QCheckBox* ImageWindow::GetSensorScopeCheckBox() const
{
    return this->sensor_scope_check_box;
}

QCheckBox* ImageWindow::GetUncoveredSensorCheckBox() const
{
    return this->uncovered_sensor_check_box;
}

QCheckBox* ImageWindow::GetDeadSensorCheckBox() const
{
    return this->dead_sensor_check_box;
}

QDialogButtonBox* ImageWindow::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QPushButton* ImageWindow::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* ImageWindow::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* ImageWindow::GetCancelButton() const
{
    return this->cancel_button;
}

void ImageWindow::SetScaleLabel(QLabel *_scale_label)
{
    this->scale_label = _scale_label;
}

void ImageWindow::SetDiameterNodeLabel(QLabel *_diameter_node_label)
{
    this->diameter_node_label = _diameter_node_label;
}

void ImageWindow::SetScaleSpinBox(QSpinBox *_scale_spin_box)
{
    this->scale_spin_box = _scale_spin_box;
}

void ImageWindow::SetDiameterNodeSpinBox(QSpinBox *_diameter_node_spin_box)
{
    this->diameter_node_spin_box = _diameter_node_spin_box;
}

void ImageWindow::SetSensorScopeCheckBox(QCheckBox *_sensor_scope_check_box)
{
    this->sensor_scope_check_box = _sensor_scope_check_box;
}

void ImageWindow::SetUncoveredNodeCheckBox(QCheckBox *_uncovered_sensor_check_box)
{
    this->uncovered_sensor_check_box = _uncovered_sensor_check_box;
}

void ImageWindow::SetDeadSensorCheckBox(QCheckBox *_dead_sensor_check_box)
{
    this->dead_sensor_check_box = _dead_sensor_check_box;
}

void ImageWindow::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

void ImageWindow::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void ImageWindow::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void ImageWindow::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

int ImageWindow::GetScale() const
{
    return this->scale;
}

int ImageWindow::GetDiameterNode() const
{
    return this->diameter_node;
}

bool ImageWindow::GetSensorScope() const
{
    return this->sensor_scope;
}

bool ImageWindow::GetUncoveredSensor() const
{
    return this->uncovered_sensor;
}

bool ImageWindow::GetDeadSensor() const
{
    return this->dead_sensor;
}

void ImageWindow::SetScale(int _scale)
{
    this->scale = _scale;
}

void ImageWindow::SetDiameterNode(int _diameter_node)
{
    this->diameter_node = _diameter_node;
}

void ImageWindow::SetSensorScope(bool _sensor_scope)
{
    this->sensor_scope = _sensor_scope;
}

void ImageWindow::SetUncoveredNode(bool _uncovered_sensor)
{
    this->uncovered_sensor = _uncovered_sensor;
}

void ImageWindow::SetDeadSensor(bool _dead_sensor)
{
    this->dead_sensor = _dead_sensor;
}

void ImageWindow::RandomValue()
{
    int _scale, _diameter;
    srand(time(0));
    _scale = this->scale_spin_box->minimum() + \
            rand() % this->scale_spin_box->maximum() + 1;
    _diameter = this->diameter_node_spin_box->minimum() + \
            rand() % this->diameter_node_spin_box->maximum() + 1;
    this->scale_spin_box->setValue(_scale);
    this->diameter_node_spin_box->setValue(_diameter);
}

void ImageWindow::SetParameters()
{
    this->scale = this->scale_spin_box->value();
    this->diameter_node = this->diameter_node_spin_box->value();
    this->sensor_scope = this->sensor_scope_check_box->isChecked();
    this->uncovered_sensor = this->uncovered_sensor_check_box->isChecked();
    this->dead_sensor = this->dead_sensor_check_box->isChecked();
}

void ImageWindow::OKClicked()
{
    SetParameters();
    this->hide();
}

void ImageWindow::CancelClicked()
{
    this->hide();
}
