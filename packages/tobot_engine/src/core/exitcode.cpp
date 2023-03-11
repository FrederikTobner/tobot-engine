#include "exitcode.h"

using namespace Tobot::Core;

int ExitCode::getCode() const {
    return this->code;
}
char const * ExitCode::getDescription() const {
    return this->description;
}
const ExitCode ExitCode::OK = ExitCode(0, "Everything went well");
const ExitCode ExitCode::CommandLineUsageError = ExitCode(64, "Layer 8 Error");
const ExitCode ExitCode::SubSystemError = ExitCode(71, "An error produces by an underlying subsystem - probably SDL");
const ExitCode ExitCode::IOError = ExitCode(74, "An error produced by an I/O operation");