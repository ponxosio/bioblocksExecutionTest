#ifndef VALVECONSOLEPLUGIN_H
#define VALVECONSOLEPLUGIN_H

#include <commonmodel/plugininterface/valvepluginproduct.h>

class ValveConsolePlugin : public ValvePluginProduct
{
public:
    ValveConsolePlugin(){}
    virtual ~ValveConsolePlugin(){}

    inline virtual void moveToPosition(int position){}
    inline virtual void closeValve(){}
};

#endif // VALVECONSOLEPLUGIN_H
