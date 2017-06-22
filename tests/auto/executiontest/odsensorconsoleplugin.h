#ifndef ODSENSORCONSOLEPLUGIN_H
#define ODSENSORCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/odsensorpluginproduct.h>

class OdSensorConsolePlugin : public OdSensorPluginProduct
{
public:
    OdSensorConsolePlugin(){od = 0.4;}
    virtual ~OdSensorConsolePlugin(){}

    inline virtual void startMeasureOd(units::Frequency measurementFrequency, units::Length waveLength){}
    inline virtual double getOdMeasurement(){ od += 0.1; return od;}

protected:
    double od;
};

#endif // ODSENSORCONSOLEPLUGIN_H
