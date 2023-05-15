#pragma once

#include "../pre_compiled_header.hpp"

namespace Tobot::IO {
    /// @brief Sets the console color to the given RGB values
    /// @param red The red value
    /// @param green The green value
    /// @param blue The blue value
    /// @return void
    auto setConsoleColor(uint8_t red, uint8_t green, uint8_t blue) -> void;

    /// @brief Resets the console color to the default color
    /// @return void
    auto resetConsoleColor() -> void;
} // namespace Tobot::IO