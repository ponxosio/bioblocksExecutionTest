#ifndef CENTRIFUGATIONCONSOLEPLUGIN_H
#define CENTRIFUGATIONCONSOLEPLUGIN_H

#include <iostream>
#include <memory>

#include <commonmodel/plugininterface/centrifugatepluginproduct.h>

class CentrifugationConsolePlugin : public CentrifugatePluginProduct
{
public:
    CentrifugationConsolePlugin(){}
    virtual ~CentrifugationConsolePlugin(){}

    inline virtual void startCentrifugate(units::Frequency intensity){}
    inline virtual void turnOff(){}
};

#endif // CENTRIFUGATIONCONSOLEPLUGIN_H
