#ifndef CDO_H
#define CDO_H

#include <iostream>
#include <random>
#include <ctime>

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QTimeEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QTime>

#include <QGraphicsItem>
#include <QGraphicsView>

enum ChemicallyType {C = 0, A, SD, HS, HA, Cp, F};
enum CharacterLocality {OA = 0, CB, RL, FA};
enum ShelterType {WALL = 0, NOWALL};
/*
DVSA - The degree of vertical stability of air -
       ступінь вертикальної стійкості повітря
*/
enum DVSA {INV, IS, CO};

/*
Глибина розповсюдження хмари зараженого повітря з уражаючими
концентраціями НХР на відкритій місцевості, км
(ємності не обваловані, швидкість вітру 1 м/с, температура повітря 0°С)

Найменування НХР        Кількість НХР в ємностях, т
                        1	5	10	20	30	50	100	300
(C)Хлор
(A)Аміак
(SD)Сірчаний ангідрид
(HS)Сірководень
(HA)Соляна кислота
(Cp)Хлорпікрин
(F)Формальдегід
*/

/*Інверсія*/
const double depth_inversion[7][8] =
{
    {4.65, 12.2, 18.5, 28.3, 36.7, 50.4, 78.7, 156.0},
    {0.5, 1.6, 2.45, 4.05, 5.25, 6.85, 10.8, 21.0},
    {2.1, 5.85, 9.25, 14.1, 18.1, 24.7, 38.4, 76.9},
    {0.5, 1.5, 2.5, 3.95, 5.0, 6.7, 10.3, 21.0},
    {1.25, 3.05, 4.65, 6.8, 8.75, 12.2, 18.7, 37.1},
    {3.65, 9.7, 14.7, 22.5, 29.3, 40.3, 62.6, 123.0},
    {4.65, 12.3, 18.7, 28.5, 28.5, 28.5, 28.5, 28.5}
};
/*Ізотермія*/
const double depth_isotherm[7][8] =
{
    {1.75, 5.05, 7.35, 11.6, 14.8, 20.2, 30.9, 62.0},
    {0.25, 0.5, 1.25, 1.55, 1.95, 2.75, 4.45, 8.35},
    {0.7, 2.4, 3.7, 5.6, 7.2, 10.2, 15.3, 30.5},
    {0.25, 0.5, 0.7, 1.4, 1.9, 2.75, 4.3, 8.15},
    {0.5, 1.3, 1.85, 2.9, 3.7, 5.0, 7.45, 14.7},
    {1.5, 4.0, 5.85, 9.2, 11.7, 15.9, 24.4, 49.4},
    {1.85, 5.1, 7.5, 11.7, 15, 20.4, 31.2, 62.5}
};
/*Конвекція*/
const double depth_convection[7][8] =
{
    {0.75, 2.4, 4.05, 6.05, 7.6, 10.7, 16.1, 31.9},
    {0.2, 0.3, 0.4, 0.5, 1.05, 1.45, 2.2, 4.55},
    {0.5, 1.3, 1.9, 3.0, 3.8, 5.1, 7.95, 15.7},
    {0.2, 0.3, 0.4, 0.5, 0.8, 1.4, 2.15, 4.4},
    {0.25, 0.5, 0.95, 1.5, 1.9, 2.6, 4.0, 7.7},
    {0.8, 2.0, 3.25, 4.85, 6.05, 8.35, 12.9, 25.2},
    {0.8, 2.45, 4.0, 6.05, 7.65, 10.7, 16.3, 32.2}
};
/*
Коефіцієнти зміни значень таблиці відносно температури
    Температура
    -20 0 +20 +40
*/
const double depth_coef_correction[4] =
    {0.95, 1, 1.05, 1.1};

/*
Поправочні коефіцієнти зменшення глибини розповсюдження
хмари зараженого повітря, залежно від швидкості вітру, КВ.
СВСП        Швидкість вітру, м/с
            1	2	3	4	5	10
Інверсія
Ізотермія
Конвекція
*/
const double wind_coef[3][6] =
{
    {1.0, 0.6, 0.45, 0.43, 0.42, 0.41},
    {1.0, 0.65, 0.55, 0.5, 0.45, 0.35},
    {1.0, 0.7, 0.6, 0.55, 0.54, 0.53}
};
/*
Коефіцієнт зменшення глибини розповсюдження хмари \
НХР при  виливі у «піддон», КСХ.
Найменування НХР        Висота обваловування, м
                        Н=0     Н=1     Н=2     Н=3
(C)Хлор
(A)Аміак
(SD)Сірчаний ангідрид
(HS)Сірководень
(HA)Соляна кислота
(Cp)Хлорпікрин
(F)Формальдегід
*/
const double length_coef[7][4] =
{
    {1.0, 2.1, 2.4, 2.5},
    {1.0, 2.0, 2.25, 2.35},
    {1.0, 2.5, 3.0, 3.1},
    {1.0, 1.6, 1.63, 1.66},
    {1.0, 4.6, 7.4, 10.0},
    {1.0, 5.3, 8.8, 11.6},
    {1.0, 2.1, 2.3, 2.5}
};
/*
Коефіцієнт зменшення глибини розповсюдження хмари НХР \
на  кожному 1 км закритої місцевості, КЗМ.
СВСП        Відкрита Міська забудова	Сільська забудова	Лісовий масив
Інверсія
Ізотермія
Конвекція
*/
const double locality_coef[3][4] =
{
    {1.0, 3.5, 3.0, 1.8},
    {1.0, 3.0, 2.5, 1.7},
    {1.0, 3.0, 2.0, 1.5}
};
/*
Середня швидкість переносу хмари забрудненого повітря, \
яка заражена речовиною W, м/с.

*/
const double speed_inversion_coef[6][2] =
{
    {2.0, 2.2},
    {4.0, 4.5},
    {6.0, 7.0},
    {6.05, 7.05},
    {6.1, 7.1},
    {6.2, 7.2}
};

const double speed_isotherm_coef[6][2] =
{
    {1.5, 2.0},
    {3.0, 4.0},
    {4.5, 6.0},
    {6.0, 8.0},
    {7.5, 10.0},
    {9.05, 12.05}
};

const double speed_convection_coef[6][2] =
{
    {1.5, 1.8},
    {3.0, 3.5},
    {4.5, 5.0},
    {4.55, 5.05},
    {4.6, 5.1},
    {4.7, 5.2}
};
/*
Час випарювання деяких СДОР, при швидкості вітру V =1 м/с, год.
Найменування НХР        Тип сховища
                        Необваловане	Обваловане
(C)Хлор
(A)Аміак
(SD)Сірчаний ангідрид
(HS)Сірководень
(HA)Соляна кислота
(Cp)Хлорпікрин
(F)Формальдегід
*/
const double shelter_coef[7][2] =
{
    {1.5, 23.9},
    {1.4, 21.8},
    {1.5, 23.9},
    {1.15, 18.4},
    {9.5, 45.7},
    {42.5, 664},
    {1.2, 19.2}
};
/*
Поправочний коефіцієнт визначення часу випаровування, \
для швидкостей вітру більше 1 м/с
*/
const double shelter_coef_correction[6] =
    {1.0, 0.75, 0.6, 0.5, 0.43, 0.25};
/*
Графік орієнтовної оцінки ступеня вертикальної стійкості повітря (СВСП)
Швидкість вітру, м/с    ясно	напів'ясно	хмарно
0-2,0
2,1-4,0
Більше 4,0
*/

const DVSA day_coef[3][3] =
{
    {CO, CO, IS},
    {CO, IS, IS},
    {IS, IS, IS}
};

const DVSA night_coef[3][3] =
{
    {INV, INV, IS},
    {INV, IS, IS},
    {IS, IS, IS}
};
/*
Допоміжні коефіцієнти для визначення тривалості випаровування НХР
*/

/*
Найменування НХР        Щільність НХР, т/м  Вражаюча токсокодоза, мг*хв/л   К1

(C)Хлор
(A)Аміак
(SD)Сірчаний ангідрид
(HS)Сірководень
(HA)Соляна кислота
(Cp)Хлорпікрин
(F)Формальдегід
*/
const double cdo_info[7][3] =
{
    {1.553, 0.6, 0.052},
    {0.681, 15.0, 0.025},
    {1.462, 1.8, 0.049},
    {0.964, 18.4, 0.042},
    {1.198, 2.0, 0.021},
    {1.658, 0.75, 0.002},
    {0.815, 0.6, 0.034}
};
/*
Найменування НХР        Температура
                        -20 0 +20 +40

(C)Хлор
(A)Аміак
(SD)Сірчаний ангідрид
(HS)Сірководень
(HA)Соляна кислота
(Cp)Хлорпікрин
(F)Формальдегід
*/
const double k2_coef[7][4] =
{
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0, 1.0},
    {0.5, 1.0, 1.0, 1.0},
    {1.0, 1.0, 1.0, 1.0},
    {0.1, 0.3, 1.0, 1.6},
    {0.1, 0.3, 1.0, 2.9},
    {1.0, 1.0, 1.0, 1.0}
};


namespace Ui {
class CDO;
}

class CDO : public QDialog
{
    Q_OBJECT
public slots:
    void RandomValue();
    void LocalityChange();
    void ShelterChange();
    void OKClicked();
    void CancelClicked();
private:
    Ui::CDO *ui;

    QLabel *type_label;
    QLabel *count_label;
    QLabel *locality_label;
    QLabel *length_label;
    QLabel *shelter_label;
    QLabel *height_label;
    QLabel *time_label;
    QLabel *x_label;
    QLabel *y_label;
    QComboBox *type_combo_box;
    QComboBox *locality_combo_box;
    QComboBox *shelter_combo_box;
    QSpinBox *count_spin_box;
    QSpinBox *length_spin_box;
    QSpinBox *height_spin_box;
    QSpinBox *x_spin_box;
    QSpinBox *y_spin_box;
    QTimeEdit *time_edit;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QDialogButtonBox *dialog_button_box;

    QGraphicsEllipseItem *zone_paint;
    QGraphicsEllipseItem *area_paint;
    QGraphicsRectItem *accident_paint;

    ChemicallyType type;
    int count;
    ShelterType shelter;
    int height;
    CharacterLocality locality;
    int length;
    QTime time;
    /*координати аварії*/
    int x;
    int y;



public:
    explicit CDO(QWidget *parent = 0);
    ~CDO();


    QLabel* GetTypeLabel() const;
    QLabel* GetCountLabel() const;
    QLabel* GetLocalityLabel() const;
    QLabel* GetLengthLabel() const;
    QLabel* GetShelterLabel() const;
    QLabel* GetHeightLabel() const;
    QLabel* GetTimeLabel() const;
    QLabel* GetXLabel() const;
    QLabel* GetYLabel() const;
    QComboBox* GetTypeComboBox() const;
    QComboBox* GetLocalityComboBox() const;
    QComboBox* GetShelterComboBox() const;
    QSpinBox* GetCountSpinBox() const;
    QSpinBox* GetLengthSpinBox() const;
    QSpinBox* GetHeightSpinBox() const;
    QSpinBox* GetXSpinBox() const;
    QSpinBox* GetYSpinBox() const;
    QTimeEdit* GetTimeEdit() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;
    QDialogButtonBox* GetDialogButtonBox() const;

    QGraphicsEllipseItem* GetZonePaint() const;
    QGraphicsEllipseItem* GetAreaPaint() const;
    QGraphicsRectItem* GetAccidentPaint() const;
    void SetZonePaint(double _depth, double _angle, double _scale, double _direction);
    void SetAreaPaint(double _depth, double _width, double _scale, double _direction, double _angle);
    void SetAccidentPaint(double _depth);
    void SetZonePaint(QGraphicsEllipseItem* _zone_paint);
    void SetAreaPaint(QGraphicsEllipseItem* _area_paint);
    void SetAccidentPaint(QGraphicsRectItem* _accident_paint);

    void SetTypeLabel(QLabel *_type_label);
    void SetCountLabel(QLabel *_count_label);
    void SetLocalityLabel(QLabel *_locality_label);
    void SetLengthLabel(QLabel *_length_label);
    void SetShelterLabel(QLabel *_shelter_label);
    void SetHeightLabel(QLabel *_height_label);
    void SetTimeLabel(QLabel *_time_label);
    void SetXLabel(QLabel *_x_label);
    void SetYLabel(QLabel *_y_label);
    void SetTypeComboBox(QComboBox *_type_combo_box);
    void SetLocalityComboBox(QComboBox *_locality_combo_box);
    void SetShelterComboBox(QComboBox *_shelter_combo_box);
    void SetCountSpinBox(QSpinBox *_count_spin_box);
    void SetLengthSpinBox(QSpinBox *_length_spin_box);
    void SetHeightSpinBox(QSpinBox *_height_spin_box);
    void SetXSpinBox(QSpinBox *_x_spin_box);
    void SetYSpinBox(QSpinBox *_y_spin_box);
    void SetTimeEdit(QTimeEdit *_time_edit);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);

    ChemicallyType GetType() const;
    int GetCount() const;
    ShelterType GetShelter() const;
    int GetHeight() const;
    CharacterLocality GetLocality() const;
    int GetLength() const;
    QTime GetTime() const;
    int GetX() const;
    int GetY() const;

    void SetType(ChemicallyType _type);
    void SetCount(int _count);
    void SetShelter(ShelterType _shelter);
    void SetHeight(int _height);
    void SetLocality(CharacterLocality _locality);
    void SetLength(int _length);
    void SetTime(QTime _time);
    void SetX(int _x);
    void SetY(int _y);

    void SetParameters();

};

#endif // CDO_H
