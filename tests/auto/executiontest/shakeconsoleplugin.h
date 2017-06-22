#ifndef SHAKECONSOLEPLUGIN_H
#define SHAKECONSOLEPLUGIN_H

#include <commonmodel/plugininterface/shakepluginproduct.h>

class ShakeConsolePlugin : public ShakePluginProduct
{
public:
    ShakeConsolePlugin(){}
    virtual ~ShakeConsolePlugin(){}

    inline virtual void startShake(units::Frequency intensity){}
    inline virtual void stopShake(){}
};

#endif // SHAKECONSOLEPLUGIN_H
