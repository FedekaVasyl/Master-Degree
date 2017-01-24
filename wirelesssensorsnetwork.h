#ifndef WIRELESSSENSORSNETWORK_H
#define WIRELESSSENSORSNETWORK_H

#include <QObject>
#include <QVector>

#include <coveragearea.h>
#include <sensor.h>
#include <processor.h>
#include <transferparameters.h>
#include <energyvalue.h>
#include <modelingwindow.h>
#include <imagewindow.h>
#include <graph.h>

class WirelessSensorsNetwork
{
public:
    WirelessSensorsNetwork();
    WirelessSensorsNetwork(int _sensor_random_value);
    virtual ~WirelessSensorsNetwork();
    CoverageArea* GetArea() const;
    QVector<Sensor*> GetNodes() const;
    int GetNodesCount() const;
    void SetNodesCount(int _count);

    Processor* GetProcessor() const;
    void SetProcessor(Processor *_processor);

    TransferParameters* GetTransferParameters() const;
    void SetTransferParameters(TransferParameters *_transfer_parameters);

    EnergyValue* GetEnergyValue() const;
    void SetEnergyValue(EnergyValue *_energy_value);

    ModelingWindow* GetModelingWindow() const;
    void SetModelingWindow(ModelingWindow *_modeling_window);

    ImageWindow* GetImageWindow() const;
    void SetImageWindow(ImageWindow *_image_window);

    Graph* GetGraph() const;
    void SetGraph(Graph *_graph);

    QVector<QVector<Sensor*>> GetClusters() const;
    QVector<Sensor*> GetClusterHeads() const;

    void SetParameters(int _sensor_random_value);
    void RisingTideAlgorithm();

    void DirectedDiffusion(double probability, int id);
    void GeographicAdaptiveFidelity(double probability, int id);
    void NewParameters();
    void Clustering();
    void RenewClusterHead();

private:
    WirelessProtocols protocol;
    CoverageArea *area;
    QVector<Sensor*> nodes;
    int nodes_count;
    Processor *processor;
    TransferParameters *transfer_parameters;
    EnergyValue *energy_value;
    ModelingWindow *modeling_window;
    ImageWindow *image_window;
    Graph *graph;


    QVector<QVector<Sensor*>> clusters;
    QVector<Sensor*> cluster_heads;

    int sensor_random_value;

};

#endif // WIRELESSSENSORSNETWORK_H
