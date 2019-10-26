#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application/Application.h"

extern Application* CreateApplication();

int main(int argc, char **argv)
{
    Application* application = CreateApplication();
    app->Run();
    delete app;
}


#endif /* ENTRYPOINT_H */

