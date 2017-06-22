#ifndef HEATERCONSOLEPLUGIN_H
#define HEATERCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/heaterpluginproduct.h>

class HeaterConsolePlugin : public HeaterPluginProduct
{
public:
    HeaterConsolePlugin(){}
    virtual ~HeaterConsolePlugin(){}

    inline virtual void changeTemperature(units::Temperature value){}
    inline virtual void turnOff(){}
};

#endif // HEATERCONSOLEPLUGIN_H
