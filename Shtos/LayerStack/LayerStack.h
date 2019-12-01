#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Layer/Layer.h"

#include <vector>

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void pushLayer(Layer *layer);
    void popLayer(Layer *layer);

    std::vector<Layer *>::iterator begin() { return _layers.begin(); };
    std::vector<Layer *>::iterator end()   { return _layers.end();   };

    std::vector<Layer *>::reverse_iterator rbegin() { return _layers.rbegin(); };
    std::vector<Layer *>::reverse_iterator rend()   { return _layers.rend();   };

private:
    std::vector<Layer *> _layers;
};

#endif /* LAYERSTACK_H */

