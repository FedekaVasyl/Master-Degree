#ifndef CHEMICALSTATUS_H
#define CHEMICALSTATUS_H

#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>

namespace Ui {
class ChemicalStatus;
}

class ChemicalStatus : public QDialog
{
    Q_OBJECT

public:
    explicit ChemicalStatus(QWidget *parent = 0);
    ~ChemicalStatus();

    QLineEdit* GetDVSALineEdit() const;
    QLineEdit* GetAngleLineEdit() const;
    QLineEdit* GetZoneLineEdit() const;
    QLineEdit* GetAreaLineEdit() const;
    QLineEdit* GetWidthLineEdit() const;
    QLineEdit* GetDepthLineEdit() const;

private:
    Ui::ChemicalStatus *ui;
    QLabel *label;
    QPixmap *pixmap;
    QLineEdit *dvsa_line_edit;
    QLineEdit *angle_line_edit;
    QLineEdit *zone_line_edit;
    QLineEdit *area_line_edit;
    QLineEdit *width_line_edit;
    QLineEdit *depth_line_edit;

};

#endif // CHEMICALSTATUS_H
