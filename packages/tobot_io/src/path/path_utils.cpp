#include "path_utils.h"

#include "../pre_compiled_header.h"

// OS-specific definitions
#if defined(OS_WINDOWS)
#define FILE_SEPERATOR ('\\')
#elif defined(OS_UNIX_LIKE)
#define FILE_SEPERATOR ('/')
#endif

int Tobot::IO::Path::getExecutablePath(char * buffer, size_t bufferSize) {
#if defined(OS_WINDOWS)
    return !GetModuleFileName(NULL, buffer, bufferSize);
#elif defined(OS_UNIX_LIKE)
    return !readlink("/proc/self/exe", buffer, bufferSize);
#endif
}

void Tobot::IO::Path::removeFileLayer(char * buffer, size_t depth) {
    if (!depth) {
        return;
    }
    size_t bufferLength = strlen(buffer);
    // Removing trailing file seperator
    if (buffer[bufferLength - 1] == FILE_SEPERATOR) {
        buffer[--bufferLength] = '\0';
    }
    for (size_t i = bufferLength - 1; i > 0; i--) {
        if (buffer[i] == FILE_SEPERATOR) {
            if (depth == 1) {
                // We don't remove the file seperator at the end
                buffer[i + 1] = '\0';
                break;
            } else {
                depth--;
            }
        }
    }
}