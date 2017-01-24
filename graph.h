#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
#include <QBrush>

namespace Ui {
class Graph;
}

class Graph : public QDialog
{
    Q_OBJECT

private:
    Ui::Graph *ui;
    QWidget graph_widget;

public:
    explicit Graph(QWidget *parent = 0);
    ~Graph();

    QVector<double> GetX() const;
    QVector<double> GetY() const;

    void SetX(QVector<double> _x);
    void SetY(QVector<double> _y);

    QVector<QVector<double>> vector_x;
    QVector<QVector<double>> vector_y;
    QVector<double> x;
    QVector<double> y;

    void Draw();

};

#endif // GRAPH_H
