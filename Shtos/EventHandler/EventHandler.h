#ifndef SHTOS_MASTER_EVENTHANDLER_H
#define SHTOS_MASTER_EVENTHANDLER_H

#include <SDL2/SDL.h>
#include "string.h"
#include <vector>


class EventHandler
{
private:
    static EventHandler* sInstance;

    Uint8* prevKeyboardState;
    Uint8* enableKeyboardState;
    const Uint8* keyboardState;
    int keyLength;

    Uint16 mouseState;
    Uint16 prevMouseState;
    int mouseXPos;
    int mouseYPos;

public:
    enum MOUSE_BUTTON{
        left = 0,
        right,
        middle
    };

    static EventHandler* Instance();
    static void Release();

    void MainHandler();
    void Update();
    void UpdatePrevInput();
    void EnableEvent(SDL_Scancode scanCode);
    void DisableEvent(SDL_Scancode scanCode);

    bool KeyDown(SDL_Scancode scanCode);
    bool KeyPressed(SDL_Scancode scanCode);
    bool KeyReleased(SDL_Scancode scanCode);

    bool MouseButtonDown(MOUSE_BUTTON button);
    bool MouseButtonPressed(MOUSE_BUTTON button);
    bool MouseButtonReleased(MOUSE_BUTTON button);
    void MouseImplementation();
    std::vector<int> MousePosition();

private:
    EventHandler();
    ~EventHandler();
};


#endif //SHTOS_MASTER_EVENTHANDLER_H
