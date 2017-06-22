#ifndef TEMPERATURESENSORCONSOLEPLUGIN_H
#define TEMPERATURESENSORCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/temperaturesensorproduct.h>

class TemperatureSensorConsolePlugin : public TemperatureSensorProduct
{
public:
    TemperatureSensorConsolePlugin(){}
    virtual ~TemperatureSensorConsolePlugin(){}

    inline virtual void startMeasureTemperature(units::Frequency measurementFrequency){}
    inline virtual units::Temperature getTemperatureMeasurement(){return 10 * units::C;}

};

#endif // TEMPERATURESENSORCONSOLEPLUGIN_H
