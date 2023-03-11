#pragma once

namespace Tobot::Core {
    class ExitCode {
        public:
            static const ExitCode OK;
            static const ExitCode USAGE;
            static const ExitCode DATAERR;
            static const ExitCode NOINPUT;
            static const ExitCode NOUSER;
            static const ExitCode NOHOST;
            static const ExitCode UNAVAILABLE;
            static const ExitCode SOFTWARE;
            static const ExitCode OSERR;
            static const ExitCode OSFILE;
            static const ExitCode CANTCREAT;
            static const ExitCode IOERR;
            static const ExitCode TEMPFAIL;
            static const ExitCode PROTOCOL;
            static const ExitCode NOPERM;
            static const ExitCode CONFIG;

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
