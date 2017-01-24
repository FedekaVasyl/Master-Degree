#include "environment.h"

Environment::Environment()
{
    this->weather = new Weather();
    this->cdo = new CDO();
    this->status = new ChemicalStatus();
    SetParameters();
}

Environment::~Environment()
{
    delete this->weather;
    delete this->cdo;
    delete this->status;
}

Weather* Environment::GetWeather() const
{
    return this->weather;
}

void Environment::SetWeather(Weather *_weather)
{
    this->weather = _weather;
}

CDO* Environment::GetCDO() const
{
    return this->cdo;
}

void Environment::SetCDO(CDO *_cdo)
{
    this->cdo = _cdo;
}

ChemicalStatus* Environment::GetStatus() const
{
    return this->status;
}

void Environment::SetStatus(ChemicalStatus *_status)
{
    this->status = _status;
}

int Environment::GetAngle() const
{
    return this->angle;
}

void Environment::SetAngle(int _angle)
{
    this->angle = _angle;
}

double Environment::GetAreaPredicted() const
{
    return this->area_predicted;
}

double Environment::GetDepthPredicted() const
{
    return this->depth_predicted;
}

DVSA Environment::GetDVSA() const
{
    return this->dvsa;
}

double Environment::GetEstimatedDepth() const
{
    return this->estimated_depth;
}

double Environment::GetFactorReduction() const
{
    return this->factor_reduction;
}

double Environment::GetFactorShelter() const
{
    return this->factor_shelter;
}

double Environment::GetFactorWind() const
{
    return this->factor_wind;
}

double Environment::GetTabularDepth() const
{
    return this->tabular_depth;
}

double Environment::GetTransferDepth() const
{
    return this->transfer_depth;
}

double Environment::GetW() const
{
    return this->w;
}

double Environment::GetWidthPredicted() const
{
    return this->width_predicted;
}

double Environment::GetZonePredicted() const
{
    return this->zone_predicted;
}

void Environment::SetAreaPredicted(double _area_predicted)
{
    this->area_predicted = _area_predicted;
}

void Environment::SetDepthPredicted(double _depth_predicted)
{
    this->depth_predicted = _depth_predicted;
}

void Environment::SetDVSA(DVSA _dvsa)
{
    this->dvsa = _dvsa;
}

void Environment::SetEstimatedDepth(double _estimated_depth)
{
    this->estimated_depth = _estimated_depth;
}

void Environment::SetFactorReduction(double _factor_reduction)
{
    this->factor_reduction = _factor_reduction;
}

void Environment::SetFactorShelter(double _factor_shelter)
{
    this->factor_shelter = _factor_shelter;
}

void Environment::SetFactorWind(double _factor_wind)
{
    this->factor_wind = _factor_wind;
}

void Environment::SetTabularDepth(double _tabular_depth)
{
    this->tabular_depth = _tabular_depth;
}

void Environment::SetTransferDepth(double _transfer_depth)
{
    this->transfer_depth = _transfer_depth;
}

void Environment::SetW(double _w)
{
    this->w = _w;
}

void Environment::SetWidthPredicted(double _width_predicted)
{
    this->width_predicted = _width_predicted;
}

void Environment::SetZonePredicted(double _zone_predicted)
{
    this->zone_predicted = _zone_predicted;
}

double Environment::GetACoef() const
{
    return this->a_coef;
}

double Environment::GetBCoef() const
{
    return this->b_coef;
}

void Environment::SetACoef(double _a)
{
    this->a_coef = _a;
}

void Environment::SetBCoef(double _b)
{
    this->b_coef = _b;
}


void Environment::SetParameters()
{
    this->GetCDO()->SetParameters();
    this->GetWeather()->SetParameters();

    this->CalculateDVSA();
    this->CalculateTabularDepth();
    this->CalculateFactorReduction();
    this->CalculateFactorShelter();
    this->CalculateFactorWind();
    this->CalculateW();

    this->CalculateEstimatedDepth();
    this->CalculateTransferDepth();

    this->CalculateDepthPredicted();
    this->CalculateWidthPredicted();
    this->CalculateAreaPredicted();
    this->CalculateZonePredicted();

    switch(this->GetDVSA())
    {
        case INV:
            {
                this->status->GetDVSALineEdit()->setText("Інверсія");
                break;
            }
        case IS:
            {
                this->status->GetDVSALineEdit()->setText("Ізотермія");
                break;
            }
        case CO:
            {
                this->status->GetDVSALineEdit()->setText("Конвекція");
                break;
            }
    }
    this->status->GetAngleLineEdit()->setText(QString::number(this->GetAngle()));
    this->status->GetAreaLineEdit()->setText(QString::number(this->GetAreaPredicted()));
    this->status->GetDepthLineEdit()->setText(QString::number(this->GetDepthPredicted()));
    this->status->GetWidthLineEdit()->setText(QString::number(this->GetWidthPredicted()));
    this->status->GetZoneLineEdit()->setText(QString::number(this->GetZonePredicted()));

}

double Environment::Interpolation(double a, double b, double c, double d, double e)
{
    double value = 0.0;
    value = a + ((b - a) / (c - d)) * (e - d);
    return value;
}

void Environment::CalculateDVSA()
{
    int *hour = new int(-1);
    int *i = new int(-1); //рядок
    int *j = new int(-1); //стовпчик
    *hour = this->GetCDO()->GetTime().hour();
    if(this->weather->GetWindSpeed() <= 2) {
        *i = 0;
    }
    else if(this->weather->GetWindSpeed() > 2 && \
            this->weather->GetWindSpeed() <= 4) {
        *i = 1;
    }
    else {
        *i = 2;
    }
    *j = int(this->weather->GetCloudiness());
    if(*hour >= 20 && *hour <= 8) {
        this->SetDVSA(night_coef[*i][*j]);
    }
    else {
        this->SetDVSA(day_coef[*i][*j]);
    }

    delete hour;
    delete i;
    delete j;
}

void Environment::CalculateTabularDepth()
{
    double *depth = new double(0.0);
    double *coef = new double(0.0);
    const int masCount = 8;
    const int tCount = 4;
    int mas[masCount] = {1, 5, 10, 20, 30, 50, 100, 300};
    int temp[tCount] = {-20, 0, 20, 40};
    int *i = new int(-1); //рядок
    int *t1 = new int(-1); //рядок в масиві корекції температури
    int *t2 = new int(-1);
    int *j1 = new int(-1); //стовпчик
    int *j2 = new int(-1);
    *i = int(this->cdo->GetType());
    switch(this->cdo->GetCount())
    {
        case 1:
            {
                *j1 = *j2 = 0;
                break;
            }
        case 5:
            {
                *j1 = *j2 = 1;
                break;
            }
        case 10:
            {
                *j1 = *j2 = 2;
                break;
            }
        case 20:
            {
                *j1 = *j2 = 3;
                break;
            }
        case 30:
            {
                *j1 = *j2 = 4;
                break;
            }
        case 50:
            {
                *j1 = *j2 = 5;
                break;
            }
        case 100:
            {
                *j1 = *j2 = 6;
                break;
            }
        case 300:
            {
                *j1 = *j2 = 7;
                break;
            }
        default:
            {
                for(int k = 1; k < masCount; k++) {
                    if(this->cdo->GetCount() < mas[k]) {
                        *j1 = k - 1;
                        *j2 = k;
                        break;
                    }
                }
                break;
            }
    }
    switch(this->weather->GetTemperature())
    {
        case -20:
            {
                *t1 = *t2 = 0;
                break;
            }
        case 0:
            {
                *t1 = *t2 = 1;
                break;
            }
        case 20:
            {
                *t1 = *t2 = 2;
                break;
            }
        case 40:
            {
                *t1 = *t2 = 3;
                break;
            }
        default:
            {
                for(int k = 1; k < tCount; k++) {
                    if(this->weather->GetTemperature() < temp[k]) {
                        *t1 = k - 1;
                        *t2 = k;
                        break;
                    }
                }
                break;
            }
    }
    switch(this->GetDVSA())
    {
        case INV:
            {
                if(*j1 == *j2) {
                    *depth = depth_inversion[*i][*j1];
                }
                else {
                    *depth = this->Interpolation(depth_inversion[*i][*j1],depth_inversion[*i][*j2],\
                                                mas[*j2],mas[*j1],this->cdo->GetCount());
                }
                break;
            }
        case IS:
            {
                if(*j1 == *j2) {
                    *depth = depth_isotherm[*i][*j1];
                }
                else {
                    *depth = this->Interpolation(depth_isotherm[*i][*j1],depth_isotherm[*i][*j2],\
                                                mas[*j2],mas[*j1],this->cdo->GetCount());
                }
                break;
            }
        case CO:
            {
                if(*j1 == *j2) {
                    *depth = depth_convection[*i][*j1];
                }
                else {
                    *depth = this->Interpolation(depth_convection[*i][*j1],depth_convection[*i][*j2],\
                                                mas[*j2],mas[*j1],this->cdo->GetCount());
                }
                break;
            }
    }

    if (*t1 == *t2) {
        *depth *= depth_coef_correction[*t1];
    }
    else {
        *coef = this->Interpolation(depth_coef_correction[*t1],depth_coef_correction[*t2],\
                                   temp[*t2],temp[*t1],this->weather->GetTemperature());
        *depth *= *coef;
    }
    this->SetTabularDepth(*depth);
    delete i;
    delete t1;
    delete t2;
    delete j1;
    delete j2;
    delete depth;
    delete coef;
}

void Environment::CalculateEstimatedDepth()
{
    double depth;
    if(this->cdo->GetLocality() == OA) {
        depth = (this->GetTabularDepth() * this->GetFactorWind()\
                / this->GetFactorShelter());
    }
    else {
        depth = (((this->GetTabularDepth() * this->GetFactorWind())\
                / this->GetFactorShelter()) - this->cdo->GetLength() + \
                (this->cdo->GetLength() / this->GetFactorReduction()));
    }
    this->SetEstimatedDepth(depth);
}

void Environment::CalculateTransferDepth()
{
    double depth;
    depth = 4 * this->GetW();
    this->SetTransferDepth(depth);
}

void Environment::CalculateDepthPredicted()
{
    if(this->GetEstimatedDepth() < this->GetTransferDepth()  && this->GetEstimatedDepth() > 0.0) {
        this->SetDepthPredicted(this->GetEstimatedDepth());
    }
    else {
        this->SetDepthPredicted(this->GetTransferDepth());
    }
}

void Environment::CalculateFactorReduction()
{
    int *i = new int(0);
    int *j = new int(0);
    switch(this->GetDVSA())
    {
        case INV:
            {
                *i = 0;
                break;
            }
        case IS:
            {
                *i = 1;
                break;
            }
        case CO:
            {
                *i = 2;
                break;
            }
    }
    *j = int(this->cdo->GetLocality());
    this->SetFactorReduction(locality_coef[*i][*j]);
    delete i;
    delete j;
}

void Environment::CalculateFactorShelter()
{
    int *i = new int(0);
    int *j = new int(0);
    *i = int(this->cdo->GetType());
    *j = this->cdo->GetHeight();
    this->SetFactorShelter(length_coef[*i][*j]);
    delete i;
    delete j;
}

void Environment::CalculateFactorWind()
{
    int *i = new int(0);
    double coef;
    switch(this->GetDVSA())
    {
        case INV:
            {
                *i = 0;
                break;
            }
        case IS:
            {
                *i = 1;
                break;
            }
        case CO:
            {
                *i = 2;
                break;
            }
    }
    if(this->weather->GetWindSpeed() > 5 && this->weather->GetWindSpeed() < 10) {
        coef = this->Interpolation(wind_coef[*i][4],wind_coef[*i][5],\
                                    10.0,5.0,double(this->weather->GetWindSpeed()));
    }
    else if(this->weather->GetWindSpeed() == 10){
        coef = wind_coef[*i][5];
    }
    else {
        coef = wind_coef[*i][this->weather->GetWindSpeed() - 1];
    }
    this->SetFactorWind(coef);
    delete i;
}

void Environment::CalculateW()
{
    int *i = new int(0);
    int *j = new int(0);
    double coef;
    if(this->cdo->GetLength() > 10) {
        *j = 1;
    }
    else {
        *j = 0;
    }
    switch(this->GetDVSA())
    {
        case INV:
            {
                if(this->weather->GetWindSpeed() > 5 && this->weather->GetWindSpeed() < 10) {
                    coef = this->Interpolation(speed_inversion_coef[4][*j],speed_inversion_coef[5][*j],\
                                                10.0,5.0,double(this->weather->GetWindSpeed()));
                }
                else if(this->weather->GetWindSpeed() == 10){
                    coef = speed_inversion_coef[5][*j];
                }
                else {
                    coef = speed_inversion_coef[this->weather->GetWindSpeed() - 1][*j];
                }
                break;
            }
        case IS:
            {
                if(this->weather->GetWindSpeed() > 5 && this->weather->GetWindSpeed() < 10) {
                    coef = this->Interpolation(speed_isotherm_coef[4][*j],speed_isotherm_coef[5][*j],\
                                                10.0,5.0,double(this->weather->GetWindSpeed()));
                }
                else if(this->weather->GetWindSpeed() == 10){
                    coef = speed_isotherm_coef[5][*j];
                }
                else {
                    coef = speed_isotherm_coef[this->weather->GetWindSpeed() - 1][*j];
                }
                break;
            }
        case CO:
            {
                if(this->weather->GetWindSpeed() > 5 && this->weather->GetWindSpeed() < 10) {
                    coef = this->Interpolation(speed_convection_coef[4][*j],speed_convection_coef[5][*j],\
                                                10.0,5.0,double(this->weather->GetWindSpeed()));
                }
                else if(this->weather->GetWindSpeed() == 10){
                    coef = speed_convection_coef[5][*j];
                }
                else {
                    coef = speed_convection_coef[this->weather->GetWindSpeed() - 1][*j];
                }
                break;
            }
    }
    this->SetW(coef);
    delete i;
    delete j;
}

void Environment::CalculateWidthPredicted()
{
    switch(this->GetDVSA())
    {
        case INV:
            {
                this->SetWidthPredicted(0.2 * this->GetDepthPredicted());
                break;
            }
        case IS:
            {
                this->SetWidthPredicted(0.35 * this->GetDepthPredicted());
                break;
            }
        case CO:
            {
                this->SetWidthPredicted(0.6 * this->GetDepthPredicted());
                break;
            }
    }
}

void Environment::CalculateAreaPredicted()
{
    this->SetAreaPredicted(0.5 * this->GetDepthPredicted() * this->GetWidthPredicted());
}

void Environment::CalculateZonePredicted()
{
    if(this->weather->GetWindSpeed() == 1) {
        this->SetZonePredicted(8.72 * 0.001 * 180 * \
                               this->GetDepthPredicted() * \
                               this->GetDepthPredicted());
        this->SetAngle(180);
    }
    else if(this->weather->GetWindSpeed() == 2) {
        this->SetZonePredicted(8.72 * 0.001 * 90 * \
                               this->GetDepthPredicted() * \
                               this->GetDepthPredicted());
        this->SetAngle(90);
    }
    else {
        this->SetZonePredicted(8.72 * 0.001 * 45 * \
                               this->GetDepthPredicted() * \
                               this->GetDepthPredicted());
        this->SetAngle(45);
    }
}
