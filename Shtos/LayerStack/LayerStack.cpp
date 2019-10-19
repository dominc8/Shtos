#include "LayerStack/LayerStack.h"
#include "Logger/Logger.h"
#include <algorithm>

LayerStack::LayerStack
{
    SHTOS_LOG_INFO("LayerStack Constructor\n");
}

LayerStack::~LayerStack
{
    SHTOS_LOG_INFO("LayerStack Destructor\n");
    for (Layer *layer : _layers)
    {
        SHTOS_LOG_INFO("Detaching and deleting Layer %s\n", layer->getName());
        layer->onDetach();
        delete layer;
    }
}

void LayerStack::pushLayer(Layer *layer)
{
    SHTOS_LOG_INFO("Pushing and attaching Layer %s\n", layer->getName());
    _layers.emplace_back(layer);
    layer->onAttach();
}

void LayerStack::popLayer(Layer *layer)
{
    auto it_layer = std::find(_layers.begin(), _layers.end(), layer);
    if (it_layer != _layers.end())
    {
        SHTOS_LOG_INFO("Detaching and popping Layer %s\n", layer->getName());
        layer->onDetach();
        _layers.erase(it_layer);
    }
}

