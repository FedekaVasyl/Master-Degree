#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <ctime>
#include <random>
#include <iostream>
using namespace std;


namespace Ui {
class Processor;
}

class Processor : public QDialog
{
    Q_OBJECT

public slots:
    void RandomValue();
    void OKClicked();
    void CancelClicked();
private:
    Ui::Processor *ui;
    QLabel *transition_time_label;
    QLabel *transition_period_label;
    QLabel *frequency_label;
    QLabel *operations_number_label;
    QLabel *commands_number_label;
    QSpinBox *transition_time_spin_box;
    QSpinBox *transition_period_spin_box;
    QSpinBox *frequency_spin_box;
    QSpinBox *operations_number_spin_box;
    QSpinBox *commands_number_spin_box;
    QDialogButtonBox *dialog_button_box;
    QPushButton *random_button;
    QPushButton *ok_button;
    QPushButton *cancel_button;

    int transition_time;
    int transition_period;
    int frequency;
    int operations_number;
    int commands_number;



public:
    explicit Processor(QWidget *parent = 0);
    ~Processor();

    QLabel* GetTransitionTimeLabel() const;
    QLabel* GetTransitionPeriodLabel() const;
    QLabel* GetFrequencyLabel() const;
    QLabel* GetOperationsNumberLabel() const;
    QLabel* GetCommandsNumberLabel() const;
    QSpinBox* GetTransitionTimeSpinBox() const;
    QSpinBox* GetTransitionPeriodSpinBox() const;
    QSpinBox* GetFrequencySpinBox() const;
    QSpinBox* GetOperationsNumberSpinBox() const;
    QSpinBox* GetCommandsNumberSpinBox() const;
    QDialogButtonBox* GetDialogButtonBox() const;
    QPushButton* GetRandomButton() const;
    QPushButton* GetOKButton() const;
    QPushButton* GetCancelButton() const;

    void SetTransitionTimeLabel(QLabel *_transition_time_label);
    void SetTransitionPeriodLabel(QLabel *_transition_period_label);
    void SetFrequencyLabel(QLabel *_frequency_label);
    void SetOperationsNumberLabel(QLabel *_operations_number_label);
    void SetCommandsNumberLabel(QLabel *_commands_number_label);
    void SetTransitionTimeSpinBox(QSpinBox *_transition_time_spin_box);
    void SetTransitionPeriodSpinBox(QSpinBox *_transition_period_spin_box);
    void SetFrequencySpinBox(QSpinBox *_frequency_spin_box);
    void SetOperationsNumberSpinBox(QSpinBox *_operations_number_spin_box);
    void SetCommandsNumberSpinBox(QSpinBox *_commands_number_spin_box);
    void SetDialogButtonBox(QDialogButtonBox *_dialog_button_box);
    void SetRandomButton(QPushButton *_random_button);
    void SetOKButton(QPushButton *_ok_button);
    void SetCancelButton(QPushButton *_cancel_button);


    int GetTransitionTime() const;
    int GetTransitionPeriod() const;
    int GetFrequency() const;
    int GetOperationsNumber() const;
    int GetCommandsNumber() const;
    void SetTransitionTime(int _transition_time);
    void SetTransitionPeriod(int _transition_period);
    void SetFrequency(int _frequency_label);
    void SetOperationsNumber(int _operations_number);
    void SetCommandsNumber(int _commands_number);

    void SetParameters();


};

#endif // PROCESSOR_H
