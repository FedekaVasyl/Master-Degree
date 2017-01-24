#include "sensor.h"

Sensor::Sensor()
{
    this->id = -1;
    this->y_coord = -1;
    this->x_coord = -1;
    this->energy_level = -1;
    this->coverage_radius = -1;
    this->protocol = DD;
    this->rank = UNCOVERED;
    this->sensor_paint = new QGraphicsEllipseItem();
    this->neighbors_id.clear();
    this->cluster_id = -1;
    this->gradient = -1;
}

Sensor::Sensor(int _id, int _x, int _y, int _coverage_radius,\
               double _energy, WirelessProtocols _protocol, SensorsRank _rank)
{
    this->id = _id;
    this->x_coord = _x;
    this->y_coord = _y;
    this->coverage_radius = _coverage_radius;
    this->energy_level = _energy;
    this->protocol = _protocol;
    this->rank = _rank;
    this->sensor_paint = new QGraphicsEllipseItem();
    this->neighbors_id.clear();
    this->cluster_id = -1;
    this->gradient = -1;
}

Sensor::~Sensor()
{
    delete this->sensor_paint;
}

double Sensor::GetEnergy() const
{
    return this->energy_level;
}

int Sensor::GetID() const
{
    return this->id;
}

WirelessProtocols Sensor::GetProtocol() const
{
    return this->protocol;
}

int Sensor::GetCoverageRadius() const
{
    return this->coverage_radius;
}

SensorsRank Sensor::GetRank() const
{
    return this->rank;
}

int Sensor::GetX() const
{
    return this->x_coord;
}

int Sensor::GetY() const
{
    return this->y_coord;
}

QVector<Sensor*> Sensor::GetNeighborsID() const
{
    return this->neighbors_id;
}

QGraphicsEllipseItem* Sensor::GetSensorPaint() const
{
    return this->sensor_paint;
}

int Sensor::GetGradient() const
{
    return this->gradient;
}

int Sensor::GetClusterID() const
{
    return this->cluster_id;
}

void Sensor::SetSensorPaint(QGraphicsEllipseItem *_sensor_paint)
{
    this->sensor_paint = _sensor_paint;
}

void Sensor::SetEnergy(double _energy)
{
    this->energy_level = _energy;
}

void Sensor::SetID(int _id)
{
    this->id = _id;
}

void Sensor::SetProtocol(WirelessProtocols _protocol)
{
    this->protocol = _protocol;
}

void Sensor::SetCoverageRadius(int _radius)
{
    this->coverage_radius = _radius;
}

void Sensor::SetRank(SensorsRank _rank)
{
    this->rank = _rank;
}

void Sensor::SetX(int _x)
{
    this->x_coord = _x;
}

void Sensor::SetY(int _y)
{
    this->y_coord = _y;
}

void Sensor::SetGradient(int _gradient)
{
    this->gradient = _gradient;
}

void Sensor::SetClusterID(int _cluster_id)
{
    this->cluster_id = _cluster_id;
}

void Sensor::SetSensorPaint(int nodes_radius)
{
    int x1, y1;
    switch(this->GetRank())
    {
        case UNCOVERED:
            {
                this->GetSensorPaint()->\
                    setBrush(QBrush(Qt::white));
                break;
            }
        case COVERED:
            {
                this->GetSensorPaint()->\
                    setBrush(QBrush(Qt::yellow));
                break;
            }
        case CENTER:
            {
                this->GetSensorPaint()->\
                    setBrush(QBrush(Qt::blue));
                break;
            }
        case DEAD:
            {
                this->GetSensorPaint()->\
                    setBrush(QBrush(Qt::red));
                break;
            }
        case MAINNODE:
            {
                this->GetSensorPaint()->\
                    setBrush(QBrush(Qt::darkGreen));
                break;
            }
    }
    x1 = this->GetX();
    y1 = this->GetY();
    this->GetSensorPaint()->setRect(x1 - nodes_radius / 2,\
                                    y1 - nodes_radius / 2,\
                                    nodes_radius,\
                                    nodes_radius);
    /*this->network->GetNodes()[i]->GetSensorPaint()->\
            setBrush(QBrush(Qt::darkGreen));*/
    this->GetSensorPaint()->\
            setPen(QPen(Qt::black, 1, Qt::SolidLine, \
                        Qt::SquareCap, Qt::MiterJoin));
}


void Sensor::FoundNeighbors(Sensor *_sensor, double radius, double consumed_energy)
{
    if(this->GetID() < 0 || _sensor->GetID() < 0) {
        return;
    }
    if(this->Crossing(this->GetX(),this->GetY(),_sensor->GetX(),_sensor->GetY(),radius) \
            && this->GetEnergy() > 1.0 && _sensor->GetEnergy() > 1.0) {
        this->neighbors_id.append(_sensor);
        this->SetEnergy(this->GetEnergy() - consumed_energy);
        _sensor->SetEnergy(_sensor->GetEnergy() - consumed_energy);
    }
}

bool Sensor::Crossing(int x1, int y1, int x2, int y2, int value)
{
    if(this->Distance(x1,y1,x2,y2) > double(value)) {
        return false;
    }
    else {
        return true;
    }
}

double Sensor::Distance(int x1, int y1, int x2, int y2)
{
    double length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return length;
}
