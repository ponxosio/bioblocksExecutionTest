#ifndef ELECTROPHORESISCONSOLEPLUGIN_H
#define ELECTROPHORESISCONSOLEPLUGIN_H

#include <iostream>
#include <memory>

#include <commonmodel/plugininterface/electrophoresispluginproduct.h>

class ElectrophoresisConsolePlugin : public ElectrophoresisPluginProduct
{
public:
    ElectrophoresisConsolePlugin(){}
    virtual ~ElectrophoresisConsolePlugin(){}

    inline virtual void startElectrophoresis(units::ElectricField fieldStrenght){}
    inline virtual std::shared_ptr<ElectrophoresisResult> stopElectrophpresis(){return NULL;}
};

#endif // ELECTROPHORESISCONSOLEPLUGIN_H
