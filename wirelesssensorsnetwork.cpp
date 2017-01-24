#include "wirelesssensorsnetwork.h"

WirelessSensorsNetwork::WirelessSensorsNetwork()
{
    this->modeling_window = new ModelingWindow();
    this->image_window = new ImageWindow();
    this->processor = new Processor();
    this->transfer_parameters = new TransferParameters();
    this->energy_value = new EnergyValue();
    this->area = new CoverageArea();
    this->graph = new Graph();
    this->sensor_random_value = 56661;
    this->SetParameters(this->sensor_random_value);
}

WirelessSensorsNetwork::WirelessSensorsNetwork(int _sensor_random_value)
{
    this->modeling_window = new ModelingWindow();
    this->image_window = new ImageWindow();
    this->processor = new Processor();
    this->transfer_parameters = new TransferParameters();
    this->energy_value = new EnergyValue();
    this->area = new CoverageArea();
    this->graph = new Graph();
    this->sensor_random_value = _sensor_random_value;
    this->SetParameters(this->sensor_random_value);
}

WirelessSensorsNetwork::~WirelessSensorsNetwork()
{
    delete this->area;
    for(int i = 0; i < this->nodes_count; i++)
        delete this->nodes[i];
    this->nodes.clear();
    delete this->processor;
    delete this->transfer_parameters;
    delete this->energy_value;
    delete this->modeling_window;
    delete this->image_window;
    delete this->graph;
}

CoverageArea* WirelessSensorsNetwork::GetArea() const
{
    return this->area;
}

QVector<Sensor*> WirelessSensorsNetwork::GetNodes() const
{
    return this->nodes;
}

int WirelessSensorsNetwork::GetNodesCount() const
{
    return this->nodes_count;
}

void WirelessSensorsNetwork::SetNodesCount(int _count)
{
    this->nodes_count = _count;
}

Processor* WirelessSensorsNetwork::GetProcessor() const
{
    return this->processor;
}

void WirelessSensorsNetwork::SetProcessor(Processor *_processor)
{
    this->processor = _processor;
}

TransferParameters* WirelessSensorsNetwork::GetTransferParameters() const
{
    return this->transfer_parameters;
}

void WirelessSensorsNetwork::SetTransferParameters(TransferParameters *_transfer_parameters)
{
    this->transfer_parameters = _transfer_parameters;
}

EnergyValue* WirelessSensorsNetwork::GetEnergyValue() const
{
    return this->energy_value;
}

void WirelessSensorsNetwork::SetEnergyValue(EnergyValue *_energy_value)
{
    this->energy_value = _energy_value;
}

ModelingWindow* WirelessSensorsNetwork::GetModelingWindow() const
{
    return this->modeling_window;
}

void WirelessSensorsNetwork::SetModelingWindow(ModelingWindow *_modeling_window)
{
    this->modeling_window = _modeling_window;
}

ImageWindow* WirelessSensorsNetwork::GetImageWindow() const
{
    return this->image_window;
}

void WirelessSensorsNetwork::SetImageWindow(ImageWindow *_image_window)
{
    this->image_window = _image_window;
}

Graph* WirelessSensorsNetwork::GetGraph() const
{
    return this->graph;
}

void WirelessSensorsNetwork::SetGraph(Graph *_graph)
{
    this->graph = _graph;
}

QVector<QVector<Sensor*>> WirelessSensorsNetwork::GetClusters() const
{
    return this->clusters;
}

QVector<Sensor*> WirelessSensorsNetwork::GetClusterHeads() const
{
    return this->cluster_heads;
}



void WirelessSensorsNetwork::SetParameters(int _sensor_random_value)
{

    this->GetModelingWindow()->SetParameters();
    this->GetImageWindow()->SetParameters();
    this->GetProcessor()->SetParameters();
    this->GetTransferParameters()->SetParameters();
    this->GetEnergyValue()->SetParameters();
    this->sensor_random_value = _sensor_random_value;

    this->GetTransferParameters()->CalculateTProc(double(this->GetProcessor()->GetTransitionPeriod()),\
                                                  this->GetProcessor()->GetCommandsNumber(),\
                                                  this->GetProcessor()->GetOperationsNumber(),\
                                                  this->GetProcessor()->GetFrequency());
    this->GetTransferParameters()->CalculateTSleep(double(this->GetProcessor()->GetTransitionTime()));

    this->GetEnergyValue()->CalculateConsumedEnergy(this->GetTransferParameters()->GetTProc(),\
                                                    this->GetTransferParameters()->GetTSleep());

    this->energy_value->CalculateNeighborsFoundEnergyReceive(this->transfer_parameters->GetTWait(),\
                                                             this->transfer_parameters->GetTCCA(),\
                                                             this->transfer_parameters->GetTData(),\
                                                             this->transfer_parameters->GetTACK());
    this->energy_value->CalculateNeighborsFoundEnergyTransfer(this->transfer_parameters->GetTWait(),\
                                                              this->transfer_parameters->GetTCCA(),\
                                                              this->transfer_parameters->GetTData(),\
                                                              this->transfer_parameters->GetTACK());
    this->protocol = WirelessProtocols(this->modeling_window->GetRoutingAlgorithm());
    this->nodes_count = this->modeling_window->GetNodeCount();
    this->nodes.clear();
    //srand(time(0));
    srand(this->sensor_random_value);
    this->nodes.append(new Sensor(0,this->modeling_window->GetX(),\
                                  this->modeling_window->GetY(),\
                                  this->transfer_parameters->GetTransferRadius(),\
                                  double(this->energy_value->GetInitialEnergy()),\
                                  WirelessProtocols(this->modeling_window->GetRoutingAlgorithm()),\
                                  MAINNODE));

    for(int i = 1; i < this->nodes_count; i++)
        {
            int x = rand() % this->modeling_window->GetWidth();
            int y = rand() % this->modeling_window->GetHeight();
            this->nodes.append(new Sensor(i,x,y,\
                                          this->transfer_parameters->GetTransferRadius(),\
                                          double(this->energy_value->GetInitialEnergy()),\
                                          WirelessProtocols(this->modeling_window->GetRoutingAlgorithm()),\
                                          UNCOVERED));
        }

    double energy = this->GetEnergyValue()->GetNeighborsFoundEnergyReceive() + \
            this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer();
    if(this->GetModelingWindow()->GetRoutingAlgorithmComboBox()->currentIndex() != 2) {
        for(int i = 0; i < this->nodes_count; i++) {
            for(int j = 0; j < this->nodes_count; j++) {
                if(i == j) {
                    continue;
                }
                this->nodes[i]->FoundNeighbors(nodes[j],\
                      this->GetTransferParameters()->GetTransferRadius(),\
                      energy);
            }
        }


        this->RisingTideAlgorithm();
    }
    else {
        this->Clustering();
    }

}

void WirelessSensorsNetwork::RisingTideAlgorithm()
{
    int *queue = new int[this->GetNodesCount()];
    bool *visited = new bool[this->GetNodesCount()];
    int start = 0;
    memset(visited,false,sizeof(bool) * this->GetNodesCount());
    memset(queue,0,sizeof(int) * this->GetNodesCount());
    queue[0] = start;
    visited[start] = true;
    int r = 0, w = 1;
    while (r < w) {
        int curr = queue[r++];
        int neighbors_count = this->GetNodes()[curr]->GetNeighborsID().count() - 1;
        while(neighbors_count != -1) {
            int node = this->GetNodes()[curr]->GetNeighborsID()[neighbors_count]->GetID();
            if (!visited[this->GetNodes()[curr]->GetNeighborsID()[neighbors_count]->GetID()]) {
                visited[this->GetNodes()[curr]->GetNeighborsID()[neighbors_count]->GetID()] = 1;
                queue[w++] = this->GetNodes()[curr]->GetNeighborsID()[neighbors_count]->GetID();
                this->GetNodes()[node]->SetRank(COVERED);
                this->GetNodes()[node]->SetGradient(curr);
            }
            this->GetNodes()[curr]->SetEnergy(this->GetNodes()[curr]->GetEnergy() - \
                                              this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer());
            this->GetNodes()[node]->SetEnergy(this->GetNodes()[node]->GetEnergy() - \
                                              this->GetEnergyValue()->GetNeighborsFoundEnergyReceive());
            neighbors_count--;
        }
    }
    delete [] queue;
    delete [] visited;
}

void WirelessSensorsNetwork::DirectedDiffusion(double probability, int id)
{
    if(id >= this->GetNodesCount()) {
        return;
    }
    if(probability < (double(this->GetModelingWindow()->GetSensitivityLimit()) / 100.0)) {
        this->GetNodes()[id]->SetEnergy(this->GetNodes()[id]->GetEnergy() - \
                                        this->GetEnergyValue()->GetConsumedEnergy());
        return;
    }
    if(this->GetNodes()[id]->GetGradient() < 0) {
        return;
    }
    while(true) {
        int node = this->GetNodes()[id]->GetGradient();
        if(node == 0) {
            this->GetNodes()[id]->SetEnergy(this->GetNodes()[id]->GetEnergy() - \
                                              (this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer() + \
                                               this->GetEnergyValue()->GetConsumedEnergy()));

            return;
        }
        this->GetNodes()[id]->SetEnergy(this->GetNodes()[id]->GetEnergy() - \
                                          (this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer() + \
                                           this->GetEnergyValue()->GetConsumedEnergy()));
        this->GetNodes()[node]->SetEnergy(this->GetNodes()[node]->GetEnergy() - \
                                         (this->GetEnergyValue()->GetNeighborsFoundEnergyReceive() + \
                                          this->GetEnergyValue()->GetConsumedEnergy()));
        id = node;
    }
}

void WirelessSensorsNetwork::GeographicAdaptiveFidelity(double probability, int id)
{
    if(id >= this->GetNodesCount()) {
        return;
    }
    if(id < 0 || this->cluster_heads[id]->GetID() < 0) {
        return;
    }
    if(this->GetNodes()[id]->GetGradient() < 0) {
        return;
    }
    if(probability < (double(this->GetModelingWindow()->GetSensitivityLimit()) / 100.0)) {
        this->cluster_heads[id]->SetEnergy(this->cluster_heads[id]->GetEnergy() - \
                                        this->GetEnergyValue()->GetConsumedEnergy());
        return;
    }

    while(true) {
        int node = this->cluster_heads[id]->GetGradient();
        if(node == 0) {
            this->cluster_heads[id]->SetEnergy(this->cluster_heads[id]->GetEnergy() - \
                                              (this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer() + \
                                               this->GetEnergyValue()->GetConsumedEnergy()));

            return;
        }
        if(id < 0 || node < 0) {
            int b;
            b = 0;
        }
        this->cluster_heads[id]->SetEnergy(cluster_heads[id]->GetEnergy() - \
                                          (this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer() + \
                                           this->GetEnergyValue()->GetConsumedEnergy()));
        if(node == -1) {
            return;
        }
        this->cluster_heads[node]->SetEnergy(this->cluster_heads[node]->GetEnergy() - \
                                         (this->GetEnergyValue()->GetNeighborsFoundEnergyReceive() + \
                                          this->GetEnergyValue()->GetConsumedEnergy()));
        id = node;
    }
}

void WirelessSensorsNetwork::NewParameters()
{

    for(int i = 0; i < this->nodes_count; i++) {
            this->nodes[i]->SetSensorPaint(new QGraphicsEllipseItem());
            this->nodes[i]->SetRank(UNCOVERED);
        }
    this->nodes[0]->SetRank(MAINNODE);
    if(this->GetModelingWindow()->GetRoutingAlgorithm() != 2) {
        for(int i = 0; i < this->nodes_count; i++) {
            for(int j = 0; j < this->nodes_count; j++) {
                if(i == j) {
                    continue;
                }
                this->nodes[i]->FoundNeighbors(nodes[j],\
                  this->GetTransferParameters()->GetTransferRadius(),\
                  this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer());
            }
        }

        this->RisingTideAlgorithm();
    }
    else {
        this->Clustering();
    }
}

void WirelessSensorsNetwork::Clustering()
{
    clusters.clear();
    cluster_heads.clear();
    int _r = int(double(this->GetTransferParameters()->GetTransferRadius()) / sqrt(5));
    int x_length = int(double(this->GetModelingWindow()->GetWidth()) / double(_r)) + 1;
    int y_length = int(double(this->GetModelingWindow()->GetHeight()) / double(_r)) + 1;
    int residual_x, residual_y;
    int total_x, total_y;
    //this->GetClusters().reserve(x_length * y_length);
    int cluster_id;
    int _count = x_length * y_length;
    if(_count < this->nodes_count) {
        _count = this->nodes_count;
    }

    QVector<Sensor*> *_vector = new QVector<Sensor*>;
    _vector->append(this->GetNodes()[0]);
    this->clusters.append(*_vector);
    for(int i = 0; i < _count; i++) {
        QVector<Sensor*> *_vector = new QVector<Sensor*>;
        this->clusters.append(*_vector);
    }
    for(int i = 1; i < this->GetModelingWindow()->GetNodeCount(); i++) {
       residual_x = this->GetNodes()[i]->GetX() % _r;
       residual_y = this->GetNodes()[i]->GetY() % _r;
       total_x = int((double(this->GetNodes()[i]->GetX()) - double(residual_x)) / _r) + 1;
       total_y = int((double(this->GetNodes()[i]->GetY()) - double(residual_y)) / _r) + 1;
       cluster_id = total_x + (total_y - 1) * x_length - 1;
       this->GetNodes()[i]->SetClusterID(cluster_id);
       clusters[cluster_id].append(this->GetNodes()[i]);
    }
    srand(time(0));
    //cluster_heads.append(this->GetNodes()[0]);
    for(int i = 0; i < clusters.count(); i++) {
        int count = clusters[i].count();
        if(count == 0) {
            cluster_heads.append(new Sensor());
            continue;
        }
        int value = rand() % count;
        //clusters[i][value]->SetRank(CENTER);
        this->cluster_heads.append(clusters[i][value]);

    }


    for(int i = 0; i < this->cluster_heads.count(); i++) {
        for(int j = 0; j < this->cluster_heads.count(); j++) {
            if(i == j) {
                continue;
            }
            this->cluster_heads[i]->FoundNeighbors(cluster_heads[j],\
                  this->GetTransferParameters()->GetTransferRadius(),\
                  this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer());
        }
    }


    int *queue = new int[cluster_heads.count()];
    bool *visited = new bool[cluster_heads.count()];
    int start = 0;
    memset(visited,false,sizeof(bool) * cluster_heads.count());
    memset(queue,0,sizeof(int) * cluster_heads.count());
    queue[0] = start;
    visited[start] = true;
    int r = 0, w = 1;
    while (r < w) {
        int curr = queue[r++];
        int neighbors_count = this->cluster_heads[curr]->GetNeighborsID().count() - 1;
        while(neighbors_count != -1) {
            int node = this->cluster_heads[curr]->GetNeighborsID()[neighbors_count]->GetClusterID();// + 1;
            if (!visited[this->cluster_heads[curr]->GetNeighborsID()[neighbors_count]->GetClusterID()]) {
                visited[this->cluster_heads[curr]->GetNeighborsID()[neighbors_count]->GetClusterID()] = 1;
                queue[w++] = this->cluster_heads[curr]->GetNeighborsID()[neighbors_count]->GetClusterID();
                this->cluster_heads[node]->SetRank(CENTER);
                this->cluster_heads[node]->SetGradient(curr);
                /*int _id = this->cluster_heads[node + 1]->GetID();
                int b;
                b = 0;*/
                this->cluster_heads[curr]->SetEnergy(this->cluster_heads[curr]->GetEnergy() - \
                                                  this->GetEnergyValue()->GetNeighborsFoundEnergyTransfer());
                this->cluster_heads[node]->SetEnergy(this->cluster_heads[node]->GetEnergy() - \
                                                  this->GetEnergyValue()->GetNeighborsFoundEnergyReceive());
            }
            neighbors_count--;
        }
    }
    delete [] queue;
    delete [] visited;

    for(int i = 0; i < clusters.count(); i++) {
        if(cluster_heads[i]->GetX() < 0) {
            continue;
        }
        if(cluster_heads[i]->GetRank() == UNCOVERED) {
            for(int j = 0; j < clusters[i].count(); j++) {
                clusters[i][j]->SetRank(UNCOVERED);
            }
            continue;
        }
        for(int j = 0; j < clusters[i].count(); j++) {
            if(clusters[i][j]->GetRank() == CENTER) {
                if(clusters[i][j]->GetNeighborsID().count() == 0) {
                    for(int k = 0; k < clusters[i].count(); k++) {
                        clusters[i][k]->SetRank(UNCOVERED);
                    }
                    break;
                }
                continue;
            }
            else {
                clusters[i][j]->SetRank(COVERED);
            }
        }
    }
    clusters[0][0]->SetRank(MAINNODE);
}

void WirelessSensorsNetwork::RenewClusterHead()
{
    srand(time(0));
    for(int i = 1; i < clusters.count(); i++) {
        if(clusters[i].count() == 0) {
            continue;
        }
        int value = rand() % clusters[i].count();
        //int new_gradient = clusters[i][value]->GetID();
        int cluster_id = clusters[i][value]->GetClusterID();
        int _id = cluster_heads[cluster_id]->GetClusterID();
        if(cluster_id != _id) {
            int b;
            b = 0;
        }
        //int was_gradient = cluster_heads[cluster_id]->GetGradient();
        /*for(int j = 0; j < cluster_heads.count(); j++) {
            if(cluster_heads[j]->GetGradient() == was_gradient) {
                cluster_heads[j]->SetGradient(new_gradient);
            }
        }*/
        cluster_heads[cluster_id] = clusters[i][value];
    }

}
