#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    ui->graph_widget->xAxis->setLabel("Період функціонування");
    ui->graph_widget->yAxis->setLabel("Спожита енергія");

    for(int i = 0; i < 4; i++) {
        QVector<double> *_vector1 = new QVector<double>;
        QVector<double> *_vector2 = new QVector<double>;
        vector_x.append(*_vector1);
        vector_y.append(*_vector2);
    }
    ui->graph_widget->legend->setVisible(true);

}

Graph::~Graph()
{
    delete ui;
}


QVector<double> Graph::GetX() const
{
    return this->x;
}

QVector<double> Graph::GetY() const
{
    return this->y;
}

void Graph::SetX(QVector<double> _x)
{
    this->x = _x;
}

void Graph::SetY(QVector<double> _y)
{
    this->y = _y;
}

void Graph::Draw()
{
    ui->graph_widget->clearGraphs();
    int k = -1;
    for(int i = 0; i < 4; i++) {
        if(vector_x[i].count() == 0) {
            continue;
        }
        ui->graph_widget->addGraph();
        k++;
        ui->graph_widget->graph(k)->addData(vector_x[i],vector_y[i]);
        if(i == 0) {
            ui->graph_widget->graph(k)->setName("DD");
            ui->graph_widget->graph(k)->setPen(QPen(Qt::red));

        }
        if(i == 2) {
            ui->graph_widget->graph(k)->setName("GAF");
        }
    }
    double x_min = 0.0;
    double x_max = 0.0;
    double X_MIN = 0.0;
    double X_MAX = 0.0;
    double y_max = 0.0;
    double y_min = 0.0;
    double Y_MIN = 0.0;
    double Y_MAX = 0.0;

    if(vector_x[0].count() > 0) {
        x_min = vector_x[0][0];
        x_max = vector_x[0][0];
        X_MIN = vector_x[0][0];
        X_MAX = vector_x[0][0];
        y_max = vector_y[0][0];
        y_min = vector_y[0][0];
        Y_MIN = vector_y[0][0];
        Y_MAX = vector_y[0][0];
    }
    else if(vector_x[1].count() > 0) {
        x_min = vector_x[1][0];
        x_max = vector_x[1][0];
        X_MIN = vector_x[1][0];
        X_MAX = vector_x[1][0];
        y_max = vector_y[1][0];
        y_min = vector_y[1][0];
        Y_MIN = vector_y[1][0];
        Y_MAX = vector_y[1][0];
    }
    else if(vector_x[2].count() > 0) {
        x_min = vector_x[2][0];
        x_max = vector_x[2][0];
        X_MIN = vector_x[2][0];
        X_MAX = vector_x[2][0];
        y_max = vector_y[2][0];
        y_min = vector_y[2][0];
        Y_MIN = vector_y[2][0];
        Y_MAX = vector_y[2][0];
    }
    else if(vector_x[3].count() > 0) {
        x_min = vector_x[3][0];
        x_max = vector_x[3][0];
        X_MIN = vector_x[3][0];
        X_MAX = vector_x[3][0];
        y_max = vector_y[3][0];
        y_min = vector_y[3][0];
        Y_MIN = vector_y[3][0];
        Y_MAX = vector_y[3][0];
    }


    for(int j = 0; j < 4; j++) {
        if(vector_x[j].count() == 0 || vector_y[j].count() == 0) {
            continue;
        }
        for(int i = 0; i < this->x.count(); i++) {
            if(vector_x[j][i] > x_max) {
                x_max = vector_x[j][i];
            }
            if(vector_x[j][i] < x_min) {
                x_min = vector_x[j][i];
            }
            if(vector_y[j][i] > y_max) {
                y_max = vector_y[j][i];
            }
            if(vector_y[j][i] < y_min) {
                y_min = vector_y[j][i];
            }
        }
        if(x_max > X_MAX) {
            X_MAX = x_max;
        }
        if(x_min < X_MIN) {
            X_MIN = x_min;
        }
        if(y_max > Y_MAX) {
            Y_MAX = y_max;
        }
        if(y_min < Y_MIN) {
            Y_MIN = y_min;
        }

    }
    ui->graph_widget->xAxis->setRange(X_MIN, X_MAX);
    ui->graph_widget->yAxis->setRange(Y_MIN, Y_MAX);
    ui->graph_widget->replot();
}
