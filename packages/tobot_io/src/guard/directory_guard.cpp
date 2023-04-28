#include "directory_guard.h"

#include "../pre_compiled_header.h"

int Tobot::IO::Directory::ensure_directory_exists(char const * folderPath) {
#ifdef OS_WINDOWS
    DWORD dataWordAttribute = GetFileAttributes(folderPath);
    if (dataWordAttribute == INVALID_FILE_ATTRIBUTES) {
        // If the directory does not exists we need to create it
        CreateDirectory(LOGS_FOLDER_PATH, NULL);
        dataWordAttribute = GetFileAttributes(folderPath);
        if (dataWordAttribute == INVALID_FILE_ATTRIBUTES) {
            std::cerr << "Can not create logs directory!\n";
            return -1;
        }
    } else if (!(dataWordAttribute & FILE_ATTRIBUTE_DIRECTORY)) {
        std::cerr << "Logs is not a directory\n";
        return -1;
    }
#endif
#ifdef OS_LINUX
    DIR * resultsDirectory = opendir(folderPath);
    if (resultsDirectory) {
        closedir(resultsDirectory);
    } else if (ENOENT == errno) {
        // If the directory does not exists we need to create it
        mkdir(LOGS_FOLDER_PATH, 0700);
        resultsDirectory = opendir(folderPath);
        if (resultsDirectory) {
            closedir(resultsDirectory);
        } else {
            std::cerr << "Can not create logs directory!\n";
            return -1;
        }
    } else {
        std::cerr << "Can not access logs directory!\n";
        return -1;
    }
#endif
    return 0;
}