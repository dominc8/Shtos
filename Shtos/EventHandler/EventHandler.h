#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL2/SDL.h>
#include "string.h"
#include <vector>


class EventHandler
{
private:
    static EventHandler* sInstance;

    Uint8* prevKeyboardState;
    Uint8* enableKeyboardState;
    Uint8* keyboardState;
    const Uint8* keyboardStateTmp;
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

    void ClearEvent(SDL_Scancode scanCode);
    int GetState(SDL_Scancode scanCode);
    int GetStateClear(SDL_Scancode scanCode);

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


#endif /* EVENTHANDLER_H */

