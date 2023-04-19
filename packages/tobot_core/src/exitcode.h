#pragma once

namespace Tobot::Core {
    class ExitCode {
        public:
            static ExitCode const OK;
            static ExitCode const USAGE;
            static ExitCode const DATAERR;
            static ExitCode const NOINPUT;
            static ExitCode const NOUSER;
            static ExitCode const NOHOST;
            static ExitCode const UNAVAILABLE;
            static ExitCode const SOFTWARE;
            static ExitCode const OSERR;
            static ExitCode const OSFILE;
            static ExitCode const CANTCREAT;
            static ExitCode const IOERR;
            static ExitCode const TEMPFAIL;
            static ExitCode const PROTOCOL;
            static ExitCode const NOPERM;
            static ExitCode const CONFIG;

        private:
            int code;
            char const * description;

        private:
            ExitCode(int code, char const * description) {
                this->code = code;
                this->description = description;
            }

        public:
            int getCode() const;
            char const * getDescription() const;
    };

} // namespace Tobot::Core
