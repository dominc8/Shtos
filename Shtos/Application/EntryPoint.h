#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application/Application.h"

extern Application* CreateApplication();

int main(int argc, char **argv)
{
    Application* application = CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif /* ENTRYPOINT_H */

