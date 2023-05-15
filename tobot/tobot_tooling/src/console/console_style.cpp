#include "console_style.hpp"

auto Tobot::IO::setConsoleColor(uint8_t red, uint8_t green, uint8_t blue) -> void {
    printf("\x1b[38;2;%d;%d;%dm", red, green, blue);
}

auto Tobot::IO::resetConsoleColor() -> void {
    printf("\x1b[39;49m");
}