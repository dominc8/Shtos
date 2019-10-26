#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <vector>

#include "Layer/Layer.h"

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void pushLayer(Layer *layer);
    void popLayer(Layer *layer);

    std::vector<Layer *>::iterator begin() { return _layers.begin(); };
    std::vector<Layer *>::iterator end()   { return _layers.end();   };

private:
    std::vector<Layer *> _layers;
};

#endif /* LAYERSTACK_H */

