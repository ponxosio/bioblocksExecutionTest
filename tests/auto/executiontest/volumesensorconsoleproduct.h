#ifndef VOLUMESENSORCONSOLEPRODUCT_H
#define VOLUMESENSORCONSOLEPRODUCT_H

#include <commonmodel/plugininterface/volumesensorproduct.h>

class VolumeSensorConsoleProduct : public VolumeSensorProduct
{
public:
    VolumeSensorConsoleProduct(){}
    virtual ~VolumeSensorConsoleProduct(){}

    inline virtual void startMeasureVolume(units::Frequency measurementFrequency){}
    inline virtual units::Volume getVolumeMeasurement(){return 10 * units::l;}
};

#endif // VOLUMESENSORCONSOLEPRODUCT_H
