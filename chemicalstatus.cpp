#include "chemicalstatus.h"
#include "ui_chemicalstatus.h"

ChemicalStatus::ChemicalStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChemicalStatus)
{
    ui->setupUi(this);
    this->label = ui->label;
    QPixmap _pixmap("image.png");
    this->label->setPixmap(_pixmap);
    this->label->show();
    this->dvsa_line_edit = ui->dvsa_line_edit;
    this->angle_line_edit = ui->angle_line_edit;
    this->zone_line_edit = ui->zone_line_edit;
    this->area_line_edit = ui->area_line_edit;
    this->width_line_edit = ui->width_line_edit;
    this->depth_line_edit = ui->depth_line_edit;
}

ChemicalStatus::~ChemicalStatus()
{
    delete ui;
}

QLineEdit* ChemicalStatus::GetAngleLineEdit() const
{
    return this->angle_line_edit;
}

QLineEdit* ChemicalStatus::GetAreaLineEdit() const
{
    return this->area_line_edit;
}

QLineEdit* ChemicalStatus::GetDepthLineEdit() const
{
    return this->depth_line_edit;
}

QLineEdit* ChemicalStatus::GetDVSALineEdit() const
{
    return this->dvsa_line_edit;
}

QLineEdit* ChemicalStatus::GetWidthLineEdit() const
{
    return this->width_line_edit;
}

QLineEdit* ChemicalStatus::GetZoneLineEdit() const
{
    return this->zone_line_edit;
}
