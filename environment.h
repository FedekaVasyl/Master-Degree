#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <cdo.h>
#include <weather.h>
#include <chemicalstatus.h>

class Environment
{
private:
    Weather *weather;
    CDO *cdo;
    ChemicalStatus *status;

    double depth_predicted;
    double width_predicted;
    double area_predicted;
    double zone_predicted;

    DVSA dvsa;
    double tabular_depth;
    double estimated_depth;
    double transfer_depth;
    double factor_wind;
    double factor_shelter;
    double factor_reduction;
    double w;
    int angle;

    double a_coef;
    double b_coef;

public:
    Environment();
    ~Environment();

    Weather* GetWeather() const;
    void SetWeather(Weather *_weather);
    CDO* GetCDO() const;
    void SetCDO(CDO *_cdo);
    ChemicalStatus* GetStatus() const;
    void SetStatus(ChemicalStatus *_status);

    double GetDepthPredicted() const;
    double GetWidthPredicted() const;
    double GetAreaPredicted() const;
    double GetZonePredicted() const;

    double GetTabularDepth() const;
    double GetEstimatedDepth() const;
    double GetTransferDepth() const;

    double GetFactorWind() const;
    double GetFactorShelter() const;
    double GetFactorReduction() const;

    double GetW() const;
    DVSA GetDVSA() const;

    int GetAngle() const;


    void SetDepthPredicted(double _depth_predicted);
    void SetWidthPredicted(double _width_predicted);
    void SetAreaPredicted(double _area_predicted);
    void SetZonePredicted(double _zone_predicted);

    void SetTabularDepth(double _tabular_depth);
    void SetEstimatedDepth(double _estimated_depth);
    void SetTransferDepth(double _transfer_depth);

    void SetFactorWind(double _factor_wind);
    void SetFactorShelter(double _factor_shelter);
    void SetFactorReduction(double _factor_reduction);

    void SetW(double _w);
    void SetDVSA(DVSA _dvsa);
    void SetAngle(int _angle);

    double GetACoef() const;
    double GetBCoef() const;

    void SetACoef(double _a);
    void SetBCoef(double _b);

    void SetParameters();

    double Interpolation(double a, double b, double c, double d, double e);

    void CalculateDVSA();
    void CalculateTabularDepth();
    void CalculateEstimatedDepth();
    void CalculateTransferDepth();

    void CalculateFactorWind();
    void CalculateFactorShelter();
    void CalculateFactorReduction();

    void CalculateW();


    void CalculateDepthPredicted();
    void CalculateWidthPredicted();
    void CalculateAreaPredicted();
    void CalculateZonePredicted();
};
#endif // ENVIRONMENT_H
