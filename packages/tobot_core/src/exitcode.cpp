#include "exitcode.h"

using namespace Tobot::Core;

int ExitCode::getCode() const {
    return this->code;
}
char const * ExitCode::getDescription() const {
    return this->description;
}
ExitCode const ExitCode::OK = ExitCode(0, "Everything went well");
ExitCode const ExitCode::USAGE = ExitCode(64, "Layer 8 Error");
ExitCode const ExitCode::DATAERR = ExitCode(65, "Data Format Error");
ExitCode const ExitCode::NOINPUT = ExitCode(66, "Can not open inpuit");
ExitCode const ExitCode::NOUSER = ExitCode(67, "Adresse unknown");
ExitCode const ExitCode::NOHOST = ExitCode(68, "Host name unknown");
ExitCode const ExitCode::UNAVAILABLE = ExitCode(69, "Service unavailable");
ExitCode const ExitCode::SOFTWARE = ExitCode(70, "Internal software error");
ExitCode const ExitCode::OSERR = ExitCode(71, "System error");
ExitCode const ExitCode::OSFILE = ExitCode(72, "Critical OS file missing");
ExitCode const ExitCode::CANTCREAT = ExitCode(73, "Cant create output file");
ExitCode const ExitCode::IOERR = ExitCode(74, "IO Error");
ExitCode const ExitCode::TEMPFAIL = ExitCode(75, "temp failure; user is invited to retry");
ExitCode const ExitCode::PROTOCOL = ExitCode(76, "remote error in protocol");
ExitCode const ExitCode::NOPERM = ExitCode(77, "Permission denied");
ExitCode const ExitCode::CONFIG = ExitCode(78, "Configuration error");