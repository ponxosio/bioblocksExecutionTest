#ifndef LIGTHCONSOLEPLUGIN_H
#define LIGTHCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/lightpluginproduct.h>

class LigthConsolePlugin : public LightPluginProduct
{
public:
    LigthConsolePlugin(){}
    virtual ~LigthConsolePlugin(){}

    inline virtual void applyLight(units::LuminousIntensity intensity, units::Length wavelenght){}
    inline virtual void turnOffLight(){}
};

#endif // LIGTHCONSOLEPLUGIN_H
