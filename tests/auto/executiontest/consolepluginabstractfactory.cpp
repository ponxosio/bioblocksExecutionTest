#include "consolepluginabstractfactory.h"

ConsolePluginAbstractFactory::ConsolePluginAbstractFactory() {

}

ConsolePluginAbstractFactory::~ConsolePluginAbstractFactory() {

}

std::shared_ptr<HeaterPluginProduct> ConsolePluginAbstractFactory::makeHeater(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<HeaterConsolePlugin>();
}

std::shared_ptr<LightPluginProduct> ConsolePluginAbstractFactory::makeLight(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<LigthConsolePlugin>();
}

std::shared_ptr<StirerPluginProduct> ConsolePluginAbstractFactory::makeStirer(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<StirerConsolePlugin>();
}

std::shared_ptr<ShakePluginProduct> ConsolePluginAbstractFactory::makeShaker(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<ShakeConsolePlugin>();
}

std::shared_ptr<CentrifugatePluginProduct> ConsolePluginAbstractFactory::makeCentrifugate(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<CentrifugationConsolePlugin>();
}

std::shared_ptr<ElectrophoresisPluginProduct> ConsolePluginAbstractFactory::makeElectrophorer(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<ElectrophoresisConsolePlugin>();
}

std::shared_ptr<OdSensorPluginProduct> ConsolePluginAbstractFactory::makeOdSensor(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<OdSensorConsolePlugin>();
}

std::shared_ptr<TemperatureSensorProduct> ConsolePluginAbstractFactory::makeTemperatureSensor(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<TemperatureSensorConsolePlugin>();
}

std::shared_ptr<LuminiscenceSensorProduct> ConsolePluginAbstractFactory::makeLuminiscenseSensor(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<LuminiscenceSensorConsolePlugin>();
}

std::shared_ptr<FluorescenceSensorProduct> ConsolePluginAbstractFactory::makeFluorescenceSensor(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<FluorescenceSensorConsolePlugin>();
}

std::shared_ptr<VolumeSensorProduct> ConsolePluginAbstractFactory::makeVolumeSensor(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<VolumeSensorConsoleProduct>();
}

std::shared_ptr<PumpPluginProduct> ConsolePluginAbstractFactory::makePump(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<PumpConsolePlugin>();
}

std::shared_ptr<ValvePluginProduct> ConsolePluginAbstractFactory::makeValve(std::shared_ptr<PluginConfiguration> configuration) {
    return std::make_shared<ValveConsolePlugin>();
}
