#pragma once

namespace Tobot::IO::Directory {
    /// @brief Ensures the logs directory exists
    /// @return 0 if the directory exists, -1 if not
    auto ensure_directory_exists(char const * folderPath) -> int;
} // namespace Tobot::IO::Directory