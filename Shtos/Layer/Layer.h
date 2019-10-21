#ifndef LAYER_H
#define LAYER_H

class Layer
{
public:
    Layer(const char* name = "Layer") : _name(name) {};
    virtual ~Layer() = default;

    virtual void onAttach() {}
    virtual void onDetach() {}
    virtual void onUpdate(float elapsed_time) {}
    // TODO: After adding Event management virtual void onEvent(Event& event) {}
    //       or handleEvents() or whatever

    const char* getName() { return _name; }

protected:
    const char* _name;
};

#endif /* LAYER_H */

