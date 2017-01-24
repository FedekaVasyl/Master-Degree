#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->graphics_view = ui->area_graphics_view;
    //this->scroll_area = ui->scroll_area;
    this->weather_menu = ui->weather_menu;
    this->cdo_menu = ui->cdo_menu;
    this->processor_menu = ui->processor_menu;
    this->transfer_menu = ui->transfer_menu;
    this->energy_menu = ui->energy_menu;
    this->modeling_menu = ui->modeling_menu;
    this->image_menu = ui->image_menu;
    this->graph_menu = ui->graph_energy_menu;
    this->evaluate_menu = ui->evaluate_menu;
    this->random_menu = ui->random_menu;

    this->build_network_button = ui->build_network_button;
    this->start_modeling_button = ui->start_modeling_button;
    this->start_modeling_button->setEnabled(false);
    this->graph_menu->setEnabled(false);
    //this->evaluate_menu->setEnabled(false);

    this->bar = ui->progressBar;
    this->is_DD = false;
    this->is_GAF = false;

    this->random_value = new RandomValue();
    this->network = new WirelessSensorsNetwork(random_value->sensor_random_value);
    this->environment = new Environment();


    this->environment->SetACoef((this->environment->GetDepthPredicted() * 1000.0) / \
                                double(this->network->GetProcessor()->GetTransitionTime()));
    this->environment->SetBCoef((this->environment->GetWidthPredicted() * 1000.0) / \
                                double(this->network->GetProcessor()->GetTransitionTime()));


    this->environment->GetCDO()->GetXSpinBox()->setMaximum\
            (this->network->GetArea()->GetWidth());
    this->environment->GetCDO()->GetYSpinBox()->setMaximum\
            (this->network->GetArea()->GetHeight());

    this->painted = false;


    QObject::connect(this->weather_menu,SIGNAL(triggered(bool)),\
                     this->environment->GetWeather(),SLOT(show()));
    QObject::connect(this->cdo_menu,SIGNAL(triggered(bool)),\
                     this->environment->GetCDO(),SLOT(show()));
    QObject::connect(this->processor_menu,SIGNAL(triggered(bool)),\
                     this->network->GetProcessor(),SLOT(show()));
    QObject::connect(this->transfer_menu,SIGNAL(triggered(bool)),\
                     this->network->GetTransferParameters(),SLOT(show()));
    QObject::connect(this->energy_menu,SIGNAL(triggered(bool)),\
                     this->network->GetEnergyValue(),SLOT(show()));
    QObject::connect(this->modeling_menu,SIGNAL(triggered(bool)),\
                     this->network->GetModelingWindow(),SLOT(show()));
    QObject::connect(this->image_menu,SIGNAL(triggered(bool)),\
                     this->network->GetImageWindow(),SLOT(show()));
    QObject::connect(this->graph_menu,SIGNAL(triggered(bool)),\
                     this->network->GetGraph(),SLOT(show()));
    QObject::connect(this->evaluate_menu,SIGNAL(triggered(bool)),\
                     this->environment->GetStatus(),SLOT(show()));
    QObject::connect(this->random_menu,SIGNAL(triggered(bool)),\
                     this->random_value,SLOT(show()));


    QObject::connect(this->network->GetArea(),SIGNAL(Draw()),\
                     this,SLOT(DrawArea()));

    QObject::connect(this->build_network_button,SIGNAL(clicked(bool)),\
                     this,SLOT(DrawNode()));
    QObject::connect(this->start_modeling_button,SIGNAL(clicked(bool)),\
                     this,SLOT(Modeling()));

    QObject::connect(this,SIGNAL(Accident()),\
                     this,SLOT(DrawAccident()));

    QObject::connect(this->network->GetEnergyValue()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->network->GetModelingWindow()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->network->GetImageWindow()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->network->GetProcessor()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->network->GetTransferParameters()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->environment->GetWeather()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));
    QObject::connect(this->environment->GetCDO()->GetOKButton(),SIGNAL(clicked(bool)),\
                     this,SLOT(NewParam()));




    emit this->network->GetArea()->Draw();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->network;
    delete this->environment;
}

QGraphicsView* MainWindow::GetGraphicsView() const
{
    return this->graphics_view;
}

QScrollArea* MainWindow::GetScrollArea() const
{
    return this->scroll_area;
}

QGraphicsScene* MainWindow::GetGraphicsScene() const
{
    return this->scene;
}

void MainWindow::SetGraphicsScene(QGraphicsScene *_scene)
{
    this->scene = _scene;
}

QAction* MainWindow::GetCDOMenu() const
{
    return this->cdo_menu;
}

QAction* MainWindow::GetWeatherMenu() const
{
    return this->weather_menu;
}

QAction* MainWindow::GetProcessorMenu() const
{
    return this->processor_menu;
}

QAction* MainWindow::GetTransferMenu() const
{
    return this->transfer_menu;
}

QAction* MainWindow::GetEnergyMenu() const
{
    return this->energy_menu;
}

QAction* MainWindow::GetModelingMenu() const
{
    return this->modeling_menu;
}

QAction* MainWindow::GetImageMenu() const
{
    return this->image_menu;
}

QAction* MainWindow::GetGraphMenu() const
{
    return this->graph_menu;
}

QAction* MainWindow::GetEvaluateMenu() const
{
    return this->evaluate_menu;
}

void MainWindow::SetWeatherMenu(QAction *_weather_menu)
{
    this->weather_menu = _weather_menu;
}

void MainWindow::SetCDOMenu(QAction *_cdo_menu)
{
    this->cdo_menu = _cdo_menu;
}

void MainWindow::SetProcessorMenu(QAction *_processor_menu)
{
    this->processor_menu = _processor_menu;
}

void MainWindow::SetTransferMenu(QAction *_transfer_menu)
{
    this->transfer_menu = _transfer_menu;
}

void MainWindow::SetEnergyMenu(QAction *_energy_menu)
{
    this->energy_menu = _energy_menu;
}

void MainWindow::SetModelingMenu(QAction *_modeling_menu)
{
    this->modeling_menu = _modeling_menu;
}

void MainWindow::SetImageMenu(QAction *_image_menu)
{
    this->image_menu = _image_menu;
}

void MainWindow::SetGraphMenu(QAction *_graph_menu)
{
    this->graph_menu = _graph_menu;
}

void MainWindow::SetEvaluateMenu(QAction *_evaluate_menu)
{
    this->evaluate_menu = _evaluate_menu;
}

Environment* MainWindow::GetEnvironment() const
{
    return this->environment;
}

void MainWindow::SetEnvironment(Environment *_environment)
{
    this->environment = _environment;
}

WirelessSensorsNetwork* MainWindow::GetNetwork() const
{
    return this->network;
}

void MainWindow::SetNetwork(WirelessSensorsNetwork *_network)
{
    this->network = _network;
}

bool MainWindow::GetPainted() const
{
    return this->painted;
}

void MainWindow::SetPainted(bool _painted)
{
    this->painted = _painted;
}



void MainWindow::DrawArea()
{
    QGraphicsScene *Scene = new QGraphicsScene(0,0,\
                                               this->network->\
                                               GetModelingWindow()->GetWidth(),\
                                               this->network->\
                                               GetModelingWindow()->GetHeight());
    this->SetGraphicsScene(Scene);
    this->GetGraphicsView()->setScene(Scene);
}

void MainWindow::DrawNode()
{

    emit this->network->GetArea()->Draw();
    this->environment->SetParameters();
    this->network->SetParameters(this->random_value->sensor_random_value);
    //this->GetGraphicsScene()->clear();
    this->environment->GetCDO()->SetAccidentPaint\
            (this->environment->GetDepthPredicted());
    this->environment->GetCDO()->SetZonePaint\
            (this->environment->GetDepthPredicted(),\
             this->environment->GetAngle(),\
             this->network->GetImageWindow()->GetScale(),\
             this->environment->GetWeather()->GetWindDirection());
    this->environment->GetCDO()->SetAreaPaint\
            (this->environment->GetDepthPredicted(),\
             this->environment->GetWidthPredicted(),\
             this->network->GetImageWindow()->GetScale(),\
             this->environment->GetWeather()->GetWindDirection(),\
             this->environment->GetAngle());

    //if(!this->GetPainted()) {
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetZonePaint());
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetAreaPaint());
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetAccidentPaint());
    if(this->network->GetModelingWindow()->GetEmergencySituation()) {
        this->environment->GetCDO()->GetZonePaint()->show();
        this->environment->GetCDO()->GetAreaPaint()->show();
        this->environment->GetCDO()->GetAccidentPaint()->show();
    }
    else {
        this->environment->GetCDO()->GetZonePaint()->hide();
        this->environment->GetCDO()->GetAreaPaint()->hide();
        this->environment->GetCDO()->GetAccidentPaint()->hide();
    }
    //if(!this->GetPainted()) {
        for(int i = 0; i < this->network->GetNodesCount(); i++)
            {
                this->network->GetNodes()[i]->SetSensorPaint(this->network->GetImageWindow()->GetDiameterNode());
                this->GetGraphicsScene()->addItem\
                    (this->network->GetNodes()[i]->GetSensorPaint());
            }

        if(this->network->GetModelingWindow()->GetRoutingAlgorithm() == 2) {
            int _r = int(double(this->network->GetTransferParameters()->GetTransferRadius()) / sqrt(5));
            int x_length = int(double(this->network->GetModelingWindow()->GetWidth()) / double(_r)) + 1;
            int y_length = int(double(this->network->GetModelingWindow()->GetHeight()) / double(_r)) + 1;
            int x1, y1, x2, y2;
            y1 = 0;
            y2 = this->network->GetModelingWindow()->GetHeight();
            for(int i = 1; i < x_length; i++) {
                x1 = x2 = _r * i;
                this->GetGraphicsScene()->addLine(x1,y1,x2,y2);
            }

            x1 = 0;
            x2 = this->network->GetModelingWindow()->GetWidth();
            for(int i = 1; i < y_length; i++) {
                y1 = y2 = _r * i;
                this->GetGraphicsScene()->addLine(x1,y1,x2,y2);
            }
        }
    this->start_modeling_button->setEnabled(true);

}

void MainWindow::DrawAccident()
{
}

void MainWindow::GenerateFreeObservation(int node_count, double *mas)
{
    srand(time(0));
    memset(mas,0,sizeof(double) * node_count);
    for(int i = 0; i < node_count; i++) {
        mas[i] = double(rand() % 3572) / 3571.00;
    }
}

void MainWindow::GenerateAccidentObservation(int node_count, double *mas, int step)
{
    srand(time(0));
    memset(mas,0,sizeof(double) * node_count);

    for(int i = 0; i < node_count; i++) {
        if(this->InEllipse(i,step)) {
            mas[i] = 1.0;
            continue;
        }
        else if(this->InSector(i,step)) {
            mas[i] = 0.5 + double(rand() % 3572) / 3571.00;
            continue;
        }
        else {
            mas[i] = double(rand() % 3572) / 3571.00;
        }
    }
}

bool MainWindow::InSector(int id, int step)
{
    double R_0 = step * this->environment->GetACoef();
    double tg, sum;
    if(R_0 > this->environment->GetDepthPredicted()) {
        return false;
    }
    if((this->network->GetNodes()[id]->GetX() - \
        this->environment->GetCDO()->GetX()) == 0) {
        tg = 2.0;
    }
    else {
        tg = tan((this->network->GetNodes()[id]->GetY() - \
                  this->environment->GetCDO()->GetY()) / \
                 (this->network->GetNodes()[id]->GetX() - \
                  this->environment->GetCDO()->GetX()));
    }
    sum = pow((this->network->GetNodes()[id]->GetY() - \
               this->environment->GetCDO()->GetY()),2) + \
          pow((this->network->GetNodes()[id]->GetX() - \
               this->environment->GetCDO()->GetX()),2);
    if(tg > 1 && sum < (R_0 * R_0)) {
        return true;
    }
    else {
        return false;
    }
}

bool MainWindow::InEllipse(int id, int step)
{
    double R_0 = step * this->environment->GetACoef();
    int x_0 = this->environment->GetCDO()->GetX() + R_0 / 2.0;
    int y_0 = this->environment->GetCDO()->GetY() + R_0 / 2.0;
    double _angle = this->environment->GetWeather()->GetWindDirection();
    if(this->environment->GetAngle() > 89.0 && this->environment->GetAngle() < 91.0) {
        _angle += 45;
    }
    else if(this->environment->GetAngle() > 179.0 && this->environment->GetAngle() < 181.0) {
        _angle = _angle;
    }
    else {
        _angle += 67;
    }
    double x = this->network->GetNodes()[id]->GetX() * \
                cos(_angle) - \
               x_0 * \
                cos(_angle);
    double y = this->network->GetNodes()[id]->GetY() * \
                sin(_angle) + \
               y_0 * \
                sin(_angle);
    double a = this->environment->GetACoef() * step;
    double b = this->environment->GetBCoef() * step;
    if((((x * x) / (a * a))  + (y * y) / (b * b)) <= 1.0) {
        return true;
    }
    else {
        return false;
    }
}

void MainWindow::Modeling()
{
    this->network->GetGraph()->x.clear();
    this->network->GetGraph()->y.clear();
    if(this->GetNetwork()->GetModelingWindow()->GetRoutingAlgorithm() == 2) {
        if(is_GAF) {
            this->network->GetGraph()->vector_x[2].clear();
            this->network->GetGraph()->vector_x[2].clear();
            is_GAF = false;
        }
        else {
            is_GAF = true;
        }
        this->GeographicAdaptiveFidelity();
        this->network->GetGraph()->vector_x[2] = this->network->GetGraph()->x;
        this->network->GetGraph()->vector_y[2] = this->network->GetGraph()->y;
    }
    else {
        if(is_DD) {
            this->network->GetGraph()->vector_x[0].clear();
            this->network->GetGraph()->vector_x[0].clear();
            is_DD = false;
        }
        else {
            is_DD = true;
        }
        this->DirectedDiffusion();
        this->network->GetGraph()->vector_x[0] = this->network->GetGraph()->x;
        this->network->GetGraph()->vector_y[0] = this->network->GetGraph()->y;
    }
    this->network->GetGraph()->Draw();
    this->graph_menu->setEnabled(true);
    this->evaluate_menu->setEnabled(true);
    this->start_modeling_button->setEnabled(false);
}

void MainWindow::DirectedDiffusion()
{
    double test_count = double(this->GetNetwork()->GetModelingWindow()->GetModelingTime()) / \
                        double(this->GetNetwork()->GetProcessor()->GetTransitionTime()) * 3600.0;
    double c = test_count / 100.0;
    int t = 1;
    for(int i = 0; i < int(test_count); i++) {
        double *pointer = new double[this->GetNetwork()->GetNodesCount()];
        if(this->network->GetModelingWindow()->GetFreeObservation()) {
            this->GenerateFreeObservation(this->GetNetwork()->GetNodesCount(),pointer);
        }
        else {
            this->GenerateAccidentObservation(this->GetNetwork()->GetNodesCount(),pointer,i);
        }
        for(int j = 1; j < this->network->GetNodesCount(); j++) {
            this->network->DirectedDiffusion(pointer[j],j);
        }
        delete [] pointer;
        this->CalculateXYGraph(i);
        if(int(c) * t == i) {
            this->bar->setValue(t++);
        }
    }
    this->bar->setValue(100);

    /*this->GetGraphicsScene()->clear();
    this->network->NewParameters();

    for(int i = 0; i < this->network->GetNodesCount(); i++) {
        this->network->GetNodes()[i]->SetSensorPaint(this->network->GetImageWindow()->GetDiameterNode());
        this->GetGraphicsScene()->addItem\
            (this->network->GetNodes()[i]->GetSensorPaint());
    }*/
}

void MainWindow::GeographicAdaptiveFidelity()
{
    double test_count = double(this->GetNetwork()->GetModelingWindow()->GetModelingTime()) / \
                        double(this->GetNetwork()->GetProcessor()->GetTransitionTime()) * 3600.0;
    double c = test_count / 100.0;
    int t = 1;
    for(int i = 0; i < int(test_count); i++) {
        double *pointer = new double[this->GetNetwork()->GetNodesCount()];
        if(this->network->GetModelingWindow()->GetFreeObservation()) {
            this->GenerateFreeObservation(this->GetNetwork()->GetNodesCount(),pointer);
        }
        else {
            this->GenerateAccidentObservation(this->GetNetwork()->GetNodesCount(),pointer,i);
        }
        for(int j = 1; j < this->network->GetClusterHeads().count(); j++) {
            this->network->GeographicAdaptiveFidelity(pointer[j],j);
        }
        delete [] pointer;
        this->CalculateXYGraph(i);
        if(int(c) * t == i) {
            this->bar->setValue(t++);
            this->GetNetwork()->RenewClusterHead();
        }
    }
    this->bar->setValue(100);
}

void MainWindow::Draw()
{
    this->GetGraphicsScene()->clear();
    this->environment->SetParameters();

    this->network->NewParameters();

    if(this->network->GetModelingWindow()->GetRoutingAlgorithm() == 2) {
        int _r = int(double(this->network->GetTransferParameters()->GetTransferRadius()) / sqrt(5));
        int x_length = int(double(this->network->GetModelingWindow()->GetWidth()) / double(_r)) + 1;
        int y_length = int(double(this->network->GetModelingWindow()->GetHeight()) / double(_r)) + 1;
        int x1, y1, x2, y2;
        y1 = 0;
        y2 = this->network->GetModelingWindow()->GetHeight();
        for(int i = 1; i < x_length; i++) {
            x1 = x2 = _r * i;
            this->GetGraphicsScene()->addLine(x1,y1,x2,y2);
        }

        x1 = 0;
        x2 = this->network->GetModelingWindow()->GetWidth();
        for(int i = 1; i < y_length; i++) {
            y1 = y2 = _r * i;
            this->GetGraphicsScene()->addLine(x1,y1,x2,y2);
        }
    }

    this->environment->GetCDO()->SetAccidentPaint\
            (this->environment->GetDepthPredicted());
    this->environment->GetCDO()->SetZonePaint\
            (this->environment->GetDepthPredicted(),\
             this->environment->GetAngle(),\
             this->network->GetImageWindow()->GetScale(),\
             this->environment->GetWeather()->GetWindDirection());
    this->environment->GetCDO()->SetAreaPaint\
            (this->environment->GetDepthPredicted(),\
             this->environment->GetWidthPredicted(),\
             this->network->GetImageWindow()->GetScale(),\
             this->environment->GetWeather()->GetWindDirection(),\
             this->environment->GetAngle());

    //if(!this->GetPainted()) {
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetZonePaint());
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetAreaPaint());
        this->GetGraphicsScene()->addItem\
                    (this->environment->GetCDO()->GetAccidentPaint());
    if(this->network->GetModelingWindow()->GetEmergencySituation()) {
        this->environment->GetCDO()->GetZonePaint()->show();
        this->environment->GetCDO()->GetAreaPaint()->show();
        this->environment->GetCDO()->GetAccidentPaint()->show();
    }
    else {
        this->environment->GetCDO()->GetZonePaint()->hide();
        this->environment->GetCDO()->GetAreaPaint()->hide();
        this->environment->GetCDO()->GetAccidentPaint()->hide();
    }

    for(int i = 0; i < this->network->GetNodesCount(); i++) {
        this->network->GetNodes()[i]->SetSensorPaint(this->network->GetImageWindow()->GetDiameterNode());
        this->GetGraphicsScene()->addItem\
            (this->network->GetNodes()[i]->GetSensorPaint());
    }
}

void MainWindow::CalculateXYGraph(int step)
{
    double e = 0.0;
    double t = double(this->network->GetProcessor()->GetTransitionTime()) * \
               double(step) / 3600.0;
    for(int i = 1; i < this->network->GetNodesCount(); i++) {
        e += (this->network->GetEnergyValue()->GetInitialEnergy() - \
              this->network->GetNodes()[i]->GetEnergy());
    }
    this->network->GetGraph()->x.append(t);
    this->network->GetGraph()->y.append(e);
}

void MainWindow::NewParam()
{
    this->start_modeling_button->setEnabled(false);
    this->graph_menu->setEnabled(false);
    this->evaluate_menu->setEnabled(false);
}
