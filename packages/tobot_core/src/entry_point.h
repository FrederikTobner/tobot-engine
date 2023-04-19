#pragma once

#include "tobot_application.h"

extern Tobot::Core::TobotApplication * Tobot::Core::CreateApplication();

int main(int argc, char ** argv) {
    std::unique_ptr<Tobot::Core::TobotApplication> application(Tobot::Core::CreateApplication());
    application->initialize();
    application->run();
    return 0;
}