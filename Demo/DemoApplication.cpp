#include "Application/EntryPoint.h"
#include "Application/Application.h"
#include "DemoLayer.h"
#include "DemoLayer2.h"
#include "Logger/Logger.h"

class DemoApplication : public Application
{
public:
    DemoApplication()
    {
        SHTOS_LOG_INFO("Demo Application starts!");
        pushLayer(new DemoLayer());
        pushLayer(new DemoLayer2());
    };
    ~DemoApplication(){
        SHTOS_LOG_INFO("Demo Application ends!");
    };
};

extern Application* CreateApplication()
{
    return new DemoApplication();
}

