#ifndef LUMINISCENCESENSORCONSOLEPLUGIN_H
#define LUMINISCENCESENSORCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/luminiscencesensorproduct.h>

class LuminiscenceSensorConsolePlugin : public LuminiscenceSensorProduct
{
public:
    LuminiscenceSensorConsolePlugin(){}
    virtual ~LuminiscenceSensorConsolePlugin(){}

    virtual void startMeasureLuminiscence(units::Frequency measurementFrequency) {}
    virtual units::LuminousIntensity getLuminiscenceMeasurement() {return 10 * units::cd;}
};

#endif // LUMINISCENCESENSORCONSOLEPLUGIN_H
