#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <vector>

#include <QMainWindow>
#include <QDialog>
#include <QGraphicsView>
#include <QScrollArea>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QAction>
#include <QProgressBar>
#include <QLine>

#include <wirelesssensorsnetwork.h>
/*#include <weather.h>
#include <cdo.h>*/
#include <environment.h>
#include <randomvalue.h>


using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void Accident();
public slots:
    void DrawArea();
    void DrawNode();
    void DrawAccident();
    void Modeling();
    void NewParam();
private:
    Ui::MainWindow *ui;

    QGraphicsView *graphics_view;
    QGraphicsScene *scene;
    QScrollArea *scroll_area;
    QAction *weather_menu;
    QAction *cdo_menu;
    QAction *processor_menu;
    QAction *transfer_menu;
    QAction *energy_menu;
    QAction *modeling_menu;
    QAction *image_menu;
    QAction *graph_menu;
    QAction *evaluate_menu;
    QAction *random_menu;

    WirelessSensorsNetwork *network;
    Environment *environment;
    RandomValue *random_value;

    bool painted;
    bool is_GAF;
    bool is_DD;


    QPushButton *build_network_button;
    QPushButton *start_modeling_button;
    QProgressBar *bar;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView* GetGraphicsView() const;
    QScrollArea* GetScrollArea() const;
    QGraphicsScene* GetGraphicsScene() const;
    void SetGraphicsScene(QGraphicsScene *_scene);

    Environment* GetEnvironment() const;
    void SetEnvironment(Environment *_environment);

    WirelessSensorsNetwork* GetNetwork() const;
    void SetNetwork(WirelessSensorsNetwork *_network);

    QAction* GetWeatherMenu() const;
    QAction* GetCDOMenu() const;
    QAction* GetProcessorMenu() const;
    QAction* GetTransferMenu() const;
    QAction* GetEnergyMenu() const;
    QAction* GetModelingMenu() const;
    QAction* GetImageMenu() const;
    QAction* GetGraphMenu() const;
    QAction* GetEvaluateMenu() const;
    void SetWeatherMenu(QAction *_weather_menu);
    void SetCDOMenu(QAction *_cdo_menu);
    void SetProcessorMenu(QAction *_processor_menu);
    void SetTransferMenu(QAction *_transfer_menu);
    void SetEnergyMenu(QAction *_energy_menu);
    void SetModelingMenu(QAction *_modeling_menu);
    void SetImageMenu(QAction *_image_menu);
    void SetGraphMenu(QAction *_graph_menu);
    void SetEvaluateMenu(QAction *_evaluate_menu);

    bool GetPainted() const;
    void SetPainted(bool _painted);

    QPushButton* GetBuildNetworkButton() const;
    QPushButton* GetStartModelingButton() const;


    void GenerateFreeObservation(int node_count, double *mas);
    void GenerateAccidentObservation(int node_count, double *mas, int step);

    void DirectedDiffusion();
    void GeographicAdaptiveFidelity();
    void Draw();

    bool InSector(int id, int step);
    bool InEllipse(int id, int step);

    void CalculateXYGraph(int step);

};

#endif // MAINWINDOW_H
