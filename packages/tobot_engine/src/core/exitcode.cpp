#include "exitcode.h"

using namespace Tobot::Core;

int ExitCode::getCode() const {
    return this->code;
}
char const * ExitCode::getDescription() const {
    return this->description;
}
const ExitCode ExitCode::OK = ExitCode(0, "Everything went well");
const ExitCode ExitCode::USAGE = ExitCode(64, "Layer 8 Error");
const ExitCode ExitCode::DATAERR = ExitCode(65, "Data Format Error");
const ExitCode ExitCode::NOINPUT = ExitCode(66, "Can not open inpuit");
const ExitCode ExitCode::NOUSER = ExitCode(67, "Adresse unknown");
const ExitCode ExitCode::NOHOST = ExitCode(68, "Host name unknown");
const ExitCode ExitCode::UNAVAILABLE = ExitCode(69, "Service unavailable");
const ExitCode ExitCode::SOFTWARE = ExitCode(70, "Internal software error");
const ExitCode ExitCode::OSERR = ExitCode(71, "System error");
const ExitCode ExitCode::OSFILE = ExitCode(72, "Critical OS file missing");
const ExitCode ExitCode::CANTCREAT = ExitCode(73, "Cant create output file");
const ExitCode ExitCode::IOERR = ExitCode(74, "IO Error");
const ExitCode ExitCode::TEMPFAIL = ExitCode(75, "temp failure; user is invited to retry");
const ExitCode ExitCode::PROTOCOL = ExitCode(76, "remote error in protocol");
const ExitCode ExitCode::NOPERM = ExitCode(77, "Permission denied");
const ExitCode ExitCode::CONFIG = ExitCode(78, "Configuration error");