#ifndef DEMOLAYER2_H
#define DEMOLAYER2_H

#include "Layer/Layer.h"

#include "stdint.h"

class DemoLayer2 : public Layer
{
public:
    DemoLayer2();
    virtual ~DemoLayer2() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time);
private:
    uint16_t _spain_texture_id;
    uint16_t _wpww_texture_id;
};

#endif /* DEMOLAYER2_H */

