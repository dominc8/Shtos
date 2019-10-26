#include "Layer/Layer.h"
#include "Logger/Logger.h"

Layer::Layer(const char *name) : _name(name)
{
    SHTOS_LOG_INFO("Constructor of Layer %s", name);
}

