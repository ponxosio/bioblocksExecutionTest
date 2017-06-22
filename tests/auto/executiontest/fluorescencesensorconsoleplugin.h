#ifndef FLUORESCENCESENSORCONSOLEPLUGIN_H
#define FLUORESCENCESENSORCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/fluorescencesensorproduct.h>

class FluorescenceSensorConsolePlugin : public FluorescenceSensorProduct
{
public:
    FluorescenceSensorConsolePlugin(){}
    virtual ~FluorescenceSensorConsolePlugin(){}

    inline virtual void startMeasureFluorescence(units::Frequency measurementFrequency, units::Length excitation, units::Length emission) {}
    inline virtual units::LuminousIntensity getFluorescenceMeasurement() {return 20 * units::cd;}
};

#endif // FLUORESCENCESENSORCONSOLEPLUGIN_H
