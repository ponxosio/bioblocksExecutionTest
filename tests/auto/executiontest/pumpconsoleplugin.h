#ifndef PUMPCONSOLEPLUGIN_H
#define PUMPCONSOLEPLUGIN_H

#include <commonmodel/plugininterface/pumppluginproduct.h>

class PumpConsolePlugin : public PumpPluginProduct
{
public:
    PumpConsolePlugin(){}
    virtual ~PumpConsolePlugin(){}

    inline virtual void setPumpState(int dir, units::Volumetric_Flow rate){}
    inline virtual void stopPump(){}
};

#endif // PUMPCONSOLEPLUGIN_H
