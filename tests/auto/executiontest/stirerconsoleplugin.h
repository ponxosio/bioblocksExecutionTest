#ifndef STIRERCONSOLEPLUGIN_H
#define STIRERCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/stirerpluginproduct.h>

class StirerConsolePlugin : public StirerPluginProduct
{
public:
    StirerConsolePlugin(){}
    virtual ~StirerConsolePlugin(){}

    inline virtual void stir(units::Frequency intensity){}
    inline virtual void turnOff(){}
};

#endif // STIRERCONSOLEPLUGIN_H
