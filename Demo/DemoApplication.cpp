#include "Application/EntryPoint.h"
#include "Application/Application.h"
#include "Logger/Logger.h"
#include "DemoLayer.h"

class DemoApplication : public Application
{
public:
    DemoApplication()
    {
        SHTOS_LOG_INFO("Demo Application starts!");
        pushLayer(new DemoLayer());
    };
    ~DemoApplication(){
        SHTOS_LOG_INFO("Demo Application ends!");
    };
};

extern Application* CreateApplication()
{
    return new DemoApplication();
}

