#include "cdo.h"
#include "ui_cdo.h"

CDO::CDO(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDO)
{
    ui->setupUi(this);

    this->type_label = ui->type_label;
    this->count_label = ui->count_label;
    this->locality_label = ui->locality_label;
    this->length_label = ui->length_label;
    this->shelter_label = ui->shelter_label;
    this->height_label = ui->height_label;
    this->time_label = ui->time_label;
    this->x_label = ui->x_label;
    this->y_label = ui->y_label;
    this->type_combo_box = ui->type_combo_box;
    this->locality_combo_box = ui->locality_combo_box;
    this->shelter_combo_box = ui->shelter_combo_box;
    this->count_spin_box = ui->count_spin_box;
    this->length_spin_box = ui->length_spin_box;
    this->height_spin_box = ui->height_spin_box;
    this->x_spin_box = ui->x_spin_box;
    this->y_spin_box = ui->y_spin_box;
    this->time_edit = ui->time_edit;
    this->random_button = ui->random_button;
    this->dialog_button_box = ui->dialog_button_box;
    this->ok_button = ui->dialog_button_box->button(QDialogButtonBox::Ok);
    this->cancel_button = ui->dialog_button_box->button(QDialogButtonBox::Cancel);

    this->shelter_combo_box->addItem("Обваловані");

    this->shelter_combo_box->addItem("Не обваловані");
    //this->shelter_combo_box->addItem("Обваловані");

    this->locality_combo_box->addItem("Сільська забудова");

    this->locality_combo_box->addItem("Відкрита місцевість");
    this->locality_combo_box->addItem("Міська забудова");
    //this->locality_combo_box->addItem("Сільська забудова");
    this->locality_combo_box->addItem("Лісовий масив");

    this->type_combo_box->addItem("Хлорпікрин");

    this->type_combo_box->addItem("Хлор");
    this->type_combo_box->addItem("Аміак");
    this->type_combo_box->addItem("Сірчаний ангідрид");
    this->type_combo_box->addItem("Сірководень");
    this->type_combo_box->addItem("Соляна кислота");
    //this->type_combo_box->addItem("Хлорпікрин");
    this->type_combo_box->addItem("Формальдегід");

    this->zone_paint = new QGraphicsEllipseItem();
    this->area_paint = new QGraphicsEllipseItem();
    this->accident_paint = new QGraphicsRectItem();

    QObject::connect(this->random_button,SIGNAL(clicked(bool)),\
                     this,SLOT(RandomValue()));
    QObject::connect(this->locality_combo_box,SIGNAL(currentIndexChanged(int)),\
                     this,SLOT(LocalityChange()));
    QObject::connect(this->shelter_combo_box,SIGNAL(currentIndexChanged(int)),\
                     this,SLOT(ShelterChange()));
    QObject::connect(this->ok_button,SIGNAL(clicked(bool)),\
                     this,SLOT(OKClicked()));
    QObject::connect(this->cancel_button,SIGNAL(clicked(bool)),\
                     this,SLOT(CancelClicked()));
    SetParameters();
}

CDO::~CDO()
{
    delete ui;
    delete this->zone_paint;
    delete this->area_paint;
    delete this->accident_paint;
}

QLabel* CDO::GetTypeLabel() const
{
    return this->type_label;
}

QLabel* CDO::GetCountLabel() const
{
    return this->count_label;
}

QLabel* CDO::GetLocalityLabel() const
{
    return this->locality_label;
}

QLabel* CDO::GetLengthLabel() const
{
    return this->length_label;
}

QLabel* CDO::GetShelterLabel() const
{
    return this->shelter_label;
}

QLabel* CDO::GetHeightLabel() const
{
    return this->height_label;
}

QLabel* CDO::GetTimeLabel() const
{
    return this->time_label;
}

QLabel* CDO::GetXLabel() const
{
    return this->x_label;
}

QLabel* CDO::GetYLabel() const
{
    return this->y_label;
}

QComboBox* CDO::GetTypeComboBox() const
{
    return this->type_combo_box;
}

QComboBox* CDO::GetLocalityComboBox() const
{
    return this->locality_combo_box;
}

QComboBox* CDO::GetShelterComboBox() const
{
    return this->shelter_combo_box;
}

QSpinBox* CDO::GetCountSpinBox() const
{
    return this->count_spin_box;
}

QSpinBox* CDO::GetLengthSpinBox() const
{
    return this->length_spin_box;
}

QSpinBox* CDO::GetHeightSpinBox() const
{
    return this->height_spin_box;
}

QSpinBox* CDO::GetXSpinBox() const
{
    return this->x_spin_box;
}

QSpinBox* CDO::GetYSpinBox() const
{
    return this->y_spin_box;
}

QTimeEdit* CDO::GetTimeEdit() const
{
    return this->time_edit;
}

QPushButton* CDO::GetRandomButton() const
{
    return this->random_button;
}

QPushButton* CDO::GetOKButton() const
{
    return this->ok_button;
}

QPushButton* CDO::GetCancelButton() const
{
    return this->cancel_button;
}

QDialogButtonBox* CDO::GetDialogButtonBox() const
{
    return this->dialog_button_box;
}

QGraphicsRectItem* CDO::GetAccidentPaint() const
{
    return this->accident_paint;
}

QGraphicsEllipseItem* CDO::GetAreaPaint() const
{
    return this->area_paint;
}

QGraphicsEllipseItem* CDO::GetZonePaint() const
{
    return this->zone_paint;
}

void CDO::SetAccidentPaint(QGraphicsRectItem *_accident_paint)
{
    this->accident_paint = _accident_paint;
}

void CDO::SetAreaPaint(QGraphicsEllipseItem *_area_paint)
{
    this->area_paint = _area_paint;
}

void CDO::SetZonePaint(QGraphicsEllipseItem *_zone_paint)
{
    this->zone_paint = _zone_paint;
}

void CDO::SetTypeLabel(QLabel *_type_label)
{
    this->type_label = _type_label;
}

void CDO::SetCountLabel(QLabel *_count_label)
{
    this->count_label = _count_label;
}

void CDO::SetLocalityLabel(QLabel *_locality_label)
{
    this->locality_label = _locality_label;
}

void CDO::SetLengthLabel(QLabel *_length_label)
{
    this->length_label = _length_label;
}

void CDO::SetShelterLabel(QLabel *_shelter_label)
{
    this->shelter_label = _shelter_label;
}

void CDO::SetHeightLabel(QLabel *_height_label)
{
    this->height_label = _height_label;
}

void CDO::SetTimeLabel(QLabel *_time_label)
{
    this->time_label = _time_label;
}

void CDO::SetXLabel(QLabel *_x_label)
{
    this->x_label = _x_label;
}

void CDO::SetYLabel(QLabel *_y_label)
{
    this->y_label = _y_label;
}

void CDO::SetTypeComboBox(QComboBox *_type_combo_box)
{
    this->type_combo_box = _type_combo_box;
}

void CDO::SetLocalityComboBox(QComboBox *_locality_combo_box)
{
    this->locality_combo_box = _locality_combo_box;
}

void CDO::SetShelterComboBox(QComboBox *_shelter_combo_box)
{
    this->shelter_combo_box = _shelter_combo_box;
}

void CDO::SetCountSpinBox(QSpinBox *_count_spin_box)
{
    this->count_spin_box = _count_spin_box;
}

void CDO::SetLengthSpinBox(QSpinBox *_length_spin_box)
{
    this->length_spin_box = _length_spin_box;
}

void CDO::SetHeightSpinBox(QSpinBox *_height_spin_box)
{
    this->height_spin_box = _height_spin_box;
}

void CDO::SetXSpinBox(QSpinBox *_x_spin_box)
{
    this->x_spin_box = _x_spin_box;
}

void CDO::SetYSpinBox(QSpinBox *_y_spin_box)
{
    this->y_spin_box = _y_spin_box;
}

void CDO::SetTimeEdit(QTimeEdit *_time_edit)
{
    this->time_edit = _time_edit;
}

void CDO::SetRandomButton(QPushButton *_random_button)
{
    this->random_button = _random_button;
}

void CDO::SetOKButton(QPushButton *_ok_button)
{
    this->ok_button = _ok_button;
}

void CDO::SetCancelButton(QPushButton *_cancel_button)
{
    this->cancel_button = _cancel_button;
}

void CDO::SetDialogButtonBox(QDialogButtonBox *_dialog_button_box)
{
    this->dialog_button_box = _dialog_button_box;
}

ChemicallyType CDO::GetType() const
{
    return this->type;
}

int CDO::GetCount() const
{
    return this->count;
}

ShelterType CDO::GetShelter() const
{
    return this->shelter;
}

int CDO::GetHeight() const
{
    return this->height;
}

CharacterLocality CDO::GetLocality() const
{
    return this->locality;
}

int CDO::GetLength() const
{
    return this->length;
}

int CDO::GetX() const
{
    return this->x;
}

int CDO::GetY() const
{
    return this->y;
}

QTime CDO::GetTime() const
{
    return this->time;
}

void CDO::SetType(ChemicallyType _type)
{
    this->type = _type;
}

void CDO::SetCount(int _count)
{
    this->count = _count;
}

void CDO::SetShelter(ShelterType _shelter)
{
    this->shelter = _shelter;
}

void CDO::SetHeight(int _height)
{
    this->height = _height;
}

void CDO::SetLocality(CharacterLocality _locality)
{
    this->locality = _locality;
}

void CDO::SetLength(int _length)
{
    this->length = _length;
}

void CDO::SetX(int _x)
{
    this->x = _x;
}

void CDO::SetY(int _y)
{
    this->y = _y;
}

void CDO::SetTime(QTime _time)
{
    this->time = _time;
}

void CDO::SetAccidentPaint(double _depth)
{
    delete this->GetAccidentPaint();
    this->accident_paint = new QGraphicsRectItem();
    int nodes_radius = 16;
    this->GetAccidentPaint()->setBrush(QBrush(Qt::red));
    this->GetAccidentPaint()->setRect(this->GetX() - nodes_radius / 2.0,\
                                      this->GetY() - nodes_radius / 2.0,\
                                      nodes_radius,\
                                      nodes_radius);
    this->GetAccidentPaint()->\
            setPen(QPen(Qt::black, 1, Qt::SolidLine, \
                        Qt::SquareCap, Qt::MiterJoin));
}

void CDO::SetZonePaint(double _depth, double _angle, double _scale, double _direction)
{
    //delete this->GetZonePaint();
    this->zone_paint = new QGraphicsEllipseItem();

    this->GetZonePaint()->setRect(this->GetX() - \
                                  _depth * _scale / 2.0,\
                                  this->GetY() - \
                                  _depth * _scale / 2.0,\
                                  _depth * _scale,\
                                  _depth * _scale);
    //this->GetZonePaint()->setStartAngle(_direction);
    this->GetZonePaint()->setTransformOriginPoint(this->GetX(), this->GetY());
    if(_angle > 89.0 && _angle < 91.0) {
        this->GetZonePaint()->setRotation(_direction + 45);
    }
    else if(_angle > 179.0 && _angle < 181.0) {
        this->GetZonePaint()->setRotation(_direction);
    }
    else {
        this->GetZonePaint()->setRotation(_direction + 67);
    }

    this->GetZonePaint()->setBrush(QBrush(Qt::darkGreen));
    this->GetZonePaint()->setPen\
            (QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    this->GetZonePaint()->setSpanAngle(_angle * (-16));
}

void CDO::SetAreaPaint(double _depth, double _width, double _scale, double _direction, double _angle)
{
    delete this->GetAreaPaint();
    this->area_paint = new QGraphicsEllipseItem();

    this->GetAreaPaint()->setTransformOriginPoint(this->GetX(), this->GetY());
    if(_angle > 89.0 && _angle < 91.0) {
        this->GetAreaPaint()->setRect(this->GetX() + \
                                      _depth * _scale / 512.0,\
                                      this->GetY() - \
                                      _width * _scale / 8.0,\
                                      _depth * _scale / 2.0,\
                                      _width * _scale / 4.0);
        this->GetAreaPaint()->setRotation(_direction + 90);
    }
    else if(_angle > 179.0 && _angle < 181.0){
        this->GetAreaPaint()->setRect(this->GetX() + \
                                      _depth * _scale / 512.0,\
                                      this->GetY() - \
                                      _width * _scale / 4.0,\
                                      _depth * _scale / 2.0,\
                                      _width * _scale / 2.0);
        this->GetAreaPaint()->setRotation(_direction + 90);
    }
    else {
        this->GetAreaPaint()->setRect(this->GetX() + \
                                      _depth * _scale / 512.0,\
                                      this->GetY() - \
                                      _width * _scale / 16.0,\
                                      _depth * _scale / 2.0,\
                                      _width * _scale / 8.0);
        this->GetAreaPaint()->setRotation(_direction + 90);
    }


    this->GetAreaPaint()->setBrush(QBrush(Qt::blue));
    this->GetAreaPaint()->setPen\
            (QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    this->GetAreaPaint()->setSpanAngle(360 * (-16));
}

void CDO::RandomValue()
{
    int _type, _count, _shelter, _height, _locality, _length;
    int _hour, _minute;
    int _x, _y;
    QTime t;
    srand(std::time(0));
    _type = rand() % 7;
    _count = 1 + rand() % 300;
    _shelter = rand() % 2;
    _height = rand() % 4;
    _locality = rand() % 4;
    _length = 1 + rand() % 10;
    _hour = rand() % 24;
    _minute = rand() % 60;
    _x = rand() % this->x_spin_box->maximum();
    _y = rand() % this->y_spin_box->maximum();
    t.setHMS(_hour,_minute,0);
    this->type_combo_box->setCurrentIndex(_type);
    this->count_spin_box->setValue(_count);
    this->shelter_combo_box->setCurrentIndex(_shelter);
    if(_shelter == 0) {
        this->height_spin_box->setValue(0);
    }
    else {
        if(_height == 0) {
            _height = 1;
        }
        this->height_spin_box->setValue(_height);
    }
    this->locality_combo_box->setCurrentIndex(_locality);
    if(_locality == 0) {
        this->length_spin_box->setValue(0);
    }
    else {
        if(_length == 0) {
            _length = 1;
        }
        this->length_spin_box->setValue(_length);
    }
    this->time_edit->setTime(t);
    this->x_spin_box->setValue(_x);
    this->y_spin_box->setValue(_y);
}

void CDO::LocalityChange()
{
    int index = this->locality_combo_box->currentIndex();
    if(index == 0) {
        this->length_spin_box->setValue(0);
    }
}

void CDO::ShelterChange()
{
    int index = this->shelter_combo_box->currentIndex();
    if(index == 0) {
        this->height_spin_box->setValue(0);
    }
}

void CDO::SetParameters()
{
    this->type = ChemicallyType(this->type_combo_box->currentIndex());
    this->count = this->count_spin_box->value();
    this->shelter = ShelterType(this->shelter_combo_box->currentIndex());
    this->height = this->height_spin_box->value();
    this->locality = CharacterLocality(this->locality_combo_box->currentIndex());
    this->length = this->length_spin_box->value();
    this->time = this->time_edit->time();
    this->x = this->x_spin_box->value();
    this->y = this->y_spin_box->value();
}

void CDO::OKClicked()
{
    SetParameters();
    this->hide();
}

void CDO::CancelClicked()
{
    this->hide();
}
