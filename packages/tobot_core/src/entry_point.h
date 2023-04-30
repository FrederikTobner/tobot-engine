#pragma once

#include "tobot_application.h"

extern Tobot::Core::TobotApplication * Tobot::Core::CreateApplication();

/// @brief Main entry point of the application.
/// @param argc The number of arguments.
/// @param argv The arguments.
/// @return 0 on success, -1 on failure.
auto main(int argc, char ** argv) -> int {
    Tobot::Core::TobotApplication * application = Tobot::Core::CreateApplication();
    application->initialize();
    application->run();
    delete application;
    return 0;
}