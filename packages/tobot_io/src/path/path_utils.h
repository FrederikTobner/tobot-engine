#pragma once

namespace Tobot::IO::Path {
    /// @brief Determines the path of the emulator executable
    /// @param buffer The buffer where the path is stored
    /// @param bufferSize The length of the buffer
    /// @return 0 if everything went well, -1 if an error occured
    auto getExecutablePath(char * buffer, size_t bufferSize) -> int;

    /// @brief Removes the specified amount of file-layers from the buffer
    /// @param buffer The buffer that is
    /// @param depth The amount of layers that are removed from the path
    auto removeFileLayer(char * buffer, size_t depth) -> void;
} // namespace Tobot::IO::Path