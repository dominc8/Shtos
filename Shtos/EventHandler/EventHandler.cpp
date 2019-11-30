#include "EventHandler/EventHandler.h"
#include "Logger/Logger.h"

#include <SDL2/SDL.h>


EventHandler* EventHandler::sInstance = NULL;

EventHandler* EventHandler::Instance()
{
    if(sInstance == NULL)
    {
        sInstance = new EventHandler();
    }
    return sInstance;
}

void EventHandler::Release()
{
    delete sInstance;
    sInstance = NULL;
}

EventHandler::EventHandler()
{
    keyboardState = SDL_GetKeyboardState(&keyLength);
    prevKeyboardState = new Uint8[keyLength];
    enableKeyboardState = new Uint8[keyLength];
    memcpy(enableKeyboardState, keyboardState, keyLength);
    memcpy(prevKeyboardState, keyboardState, keyLength);

    //Enable all events
    for(int i = 0; i < keyLength; ++i)
    {
        enableKeyboardState[i] = 1;
    }
}

EventHandler::~EventHandler()
{
    delete[] prevKeyboardState;
    delete[] enableKeyboardState;
    prevKeyboardState = NULL;
}

void EventHandler::MainHandler()
{

    Update();
    //W BUTTON implementation
    if(KeyPressed(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("W PRESSED");
    }
    if(KeyDown(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("W DOWN");
    }
    if(KeyReleased(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("W RELEASED");
    }

    //S BUTTON implementation
    if(KeyPressed(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("S PRESSED");
    }
    if(KeyDown(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("S DOWN");
    }
    if(KeyReleased(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("S RELEASED");
    }

    //MouseImplementation();

    UpdatePrevInput();
}

void EventHandler::EnableEvent(SDL_Scancode scanCode)
{
    enableKeyboardState[scanCode] = 1;
}

void EventHandler::DisableEvent(SDL_Scancode scanCode)
{
    enableKeyboardState[scanCode] = 0;
}




bool EventHandler::KeyDown(SDL_Scancode scanCode)
{
    return keyboardState[scanCode] && enableKeyboardState[scanCode];
}

bool EventHandler::KeyPressed(SDL_Scancode scanCode)
{
    return !prevKeyboardState[scanCode] && keyboardState[scanCode] && enableKeyboardState[scanCode];
}

bool EventHandler::KeyReleased(SDL_Scancode scanCode)
{
    return prevKeyboardState[scanCode] && !keyboardState[scanCode] && enableKeyboardState[scanCode];
}




std::vector<int> EventHandler::MousePosition()
{
    std::vector<int> v = {mouseXPos, mouseYPos};
    return v;
}

bool EventHandler::MouseButtonDown(MOUSE_BUTTON button)
{
    Uint32 mask = 0;

    switch(button) {
        case left:

            mask = SDL_BUTTON_LMASK;
            break;

        case right:

            mask = SDL_BUTTON_RMASK;
            break;

        case middle:

            mask = SDL_BUTTON_MMASK;
            break;
    }

    return (mouseState & mask);
}

bool EventHandler::MouseButtonPressed(MOUSE_BUTTON button)
{
    Uint32 mask = 0;

    switch(button) {
        case left:

            mask = SDL_BUTTON_LMASK;
            break;

        case right:

            mask = SDL_BUTTON_RMASK;
            break;

        case middle:

            mask = SDL_BUTTON_MMASK;
            break;
    }

    return !(prevMouseState & mask) && (mouseState & mask);
}

bool EventHandler::MouseButtonReleased(MOUSE_BUTTON button)
{
    Uint32 mask = 0;

    switch(button) {
        case left:

            mask = SDL_BUTTON_LMASK;
            break;

        case right:

            mask = SDL_BUTTON_RMASK;
            break;

        case middle:

            mask = SDL_BUTTON_MMASK;
            break;
    }

    return (prevMouseState & mask) && !(mouseState & mask);
}

void EventHandler::MouseImplementation()
{

//RIGHT BUTTON CAPTURE--------------------------------------------------
    if(MouseButtonPressed(right))
    {
        SHTOS_LOG_INFO("RIGHT MOUSE button pressed.");
    }
    if(MouseButtonDown(right))
    {
        SHTOS_LOG_INFO("RIGHT MOUSE button down.");
    }
    if(MouseButtonReleased(right))
    {
        SHTOS_LOG_INFO("RIGHT MOUSE button released.");
    }

//LEFT BUTTON CAPTURE--------------------------------------------------
    if(MouseButtonPressed(left))
    {
        SHTOS_LOG_INFO("LEFT MOUSE button pressed.");
    }
    if(MouseButtonDown(left))
    {
        SHTOS_LOG_INFO("LEFT MOUSE button down.");
    }
    if(MouseButtonReleased(left))
    {
        SHTOS_LOG_INFO("LEFT MOUSE button released.");
    }

//MIDDLE BUTTON CAPTURE--------------------------------------------------
    if(MouseButtonPressed(middle))
    {
        SHTOS_LOG_INFO("MIDDLE MOUSE button pressed.");
    }
    if(MouseButtonDown(middle))
    {
        SHTOS_LOG_INFO("MIDDLE MOUSE button down.");
    }
    if(MouseButtonReleased(middle))
    {
        SHTOS_LOG_INFO("MIDDLE MOUSE button released.");
    }

    //Capturing mouse position.
    //std::vector<int> v = MousePosition();
    //printf("MouseX: %i,    MouseY: %i\n", v.at(0), v.at(1));
}



void EventHandler::Update()
{
    mouseState = SDL_GetMouseState(&mouseXPos, &mouseYPos);
    keyboardState = SDL_GetKeyboardState(NULL);
}

void EventHandler::UpdatePrevInput()
{
    memcpy(prevKeyboardState, keyboardState, keyLength);
    prevMouseState = mouseState;
}