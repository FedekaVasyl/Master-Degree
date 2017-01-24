#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsView>

enum WirelessProtocols {DD = 0, DP, GAF, TDD};
enum SensorsRank {UNCOVERED = 0, COVERED, CENTER, DEAD, MAINNODE};

class Sensor : public QObject
{
    Q_OBJECT

signals:
    void Draw();
private:
    QGraphicsEllipseItem *sensor_paint;
    int id;
    int x_coord;
    int y_coord;
    int coverage_radius;
    double energy_level;

    WirelessProtocols protocol;
    SensorsRank rank;

    QVector<Sensor*> neighbors_id;
    int gradient;

    int cluster_id;
public:
    Sensor();
    Sensor(int _id, int _x, int _y, int _coverage_radius,\
           double _energy, WirelessProtocols _protocol, SensorsRank _rank);
    virtual ~Sensor();

    QGraphicsEllipseItem* GetSensorPaint() const;
    int GetID() const;
    int GetX() const;
    int GetY() const;
    int GetCoverageRadius() const;
    double GetEnergy() const;
    QVector<Sensor*> GetNeighborsID() const;
    WirelessProtocols GetProtocol() const;
    SensorsRank GetRank() const;
    int GetGradient() const;
    int GetClusterID() const;

    void SetSensorPaint(int nodes_radius);
    void SetSensorPaint(QGraphicsEllipseItem *_sensor_paint);
    void SetID(int _id);
    void SetX(int _x);
    void SetY(int _y);
    void SetCoverageRadius(int _radius);
    void SetEnergy(double _energy);
    void SetProtocol(WirelessProtocols _protocol);
    void SetRank(SensorsRank _rank);
    void SetGradient(int _gradient);
    void SetClusterID(int _cluster_id);

    void FoundNeighbors(Sensor *_sensor, double radius, double consumed_energy);
    bool Crossing(int x1, int y1, int x2, int y2, int value);
    double Distance(int x1, int y1, int x2, int y2);
};

#endif // SENSOR_H
