#ifndef DEMOLAYER_H
#define DEMOLAYER_H

#include "Layer/Layer.h"

class DemoLayer : public Layer
{
public:
    DemoLayer();
    virtual ~DemoLayer() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time);
};

#endif /* DEMOLAYER_H */

