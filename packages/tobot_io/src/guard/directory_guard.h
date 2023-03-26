#pragma once

namespace Tobot::IO::Directory {
    /// @brief Ensures the logs directory exists
    /// @return 0 if the directory exists, -1 if not
    int ensure_directory_exists(char const * folderPath);
} // namespace Tobot::IO::Directory