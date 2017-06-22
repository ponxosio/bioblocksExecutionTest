#ifndef CONSOLEPLUGINABSTRACTFACTORY_H
#define CONSOLEPLUGINABSTRACTFACTORY_H

#include <memory>

#include <commonmodel/plugininterface/pluginabstractfactory.h>

#include "centrifugationconsoleplugin.h"
#include "electrophoresisconsoleplugin.h"
#include "fluorescencesensorconsoleplugin.h"
#include "heaterconsoleplugin.h"
#include "ligthconsoleplugin.h"
#include "luminiscencesensorconsoleplugin.h"
#include "odsensorconsoleplugin.h"
#include "pumpconsoleplugin.h"
#include "shakeconsoleplugin.h"
#include "stirerconsoleplugin.h"
#include "temperaturesensorconsoleplugin.h"
#include "valveconsoleplugin.h"
#include "volumesensorconsoleproduct.h"

class ConsolePluginAbstractFactory : public PluginAbstractFactory
{
public:
    ConsolePluginAbstractFactory();
    virtual ~ConsolePluginAbstractFactory();

    virtual std::shared_ptr<HeaterPluginProduct> makeHeater(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<LightPluginProduct> makeLight(std::shared_ptr<PluginConfiguration> configuration);

    virtual std::shared_ptr<StirerPluginProduct> makeStirer(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<ShakePluginProduct> makeShaker(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<CentrifugatePluginProduct> makeCentrifugate(std::shared_ptr<PluginConfiguration> configuration);

    virtual std::shared_ptr<ElectrophoresisPluginProduct> makeElectrophorer(std::shared_ptr<PluginConfiguration> configuration);

    virtual std::shared_ptr<OdSensorPluginProduct> makeOdSensor(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<TemperatureSensorProduct> makeTemperatureSensor(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<LuminiscenceSensorProduct> makeLuminiscenseSensor(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<FluorescenceSensorProduct> makeFluorescenceSensor(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<VolumeSensorProduct> makeVolumeSensor(std::shared_ptr<PluginConfiguration> configuration);

    virtual std::shared_ptr<PumpPluginProduct> makePump(std::shared_ptr<PluginConfiguration> configuration);
    virtual std::shared_ptr<ValvePluginProduct> makeValve(std::shared_ptr<PluginConfiguration> configuration);
};

#endif // CONSOLEPLUGINABSTRACTFACTORY_H
