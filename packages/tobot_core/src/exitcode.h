#pragma once

namespace Tobot::Core {
    class ExitCode {
        public:
            /// @brief The exit code for a successful execution
            static ExitCode const OK;

            /// @brief The exit code for a usage error
            static ExitCode const USAGE;

            /// @brief The exit code for a data format error
            static ExitCode const DATAERR;

            /// @brief The exit code for a no input error
            static ExitCode const NOINPUT;

            /// @brief The exit code for a no user error
            static ExitCode const NOUSER;

            /// @brief The exit code for a no host error
            static ExitCode const NOHOST;

            /// @brief The exit code for a service unavailable error
            static ExitCode const UNAVAILABLE;

            /// @brief The exit code for a internal software error
            static ExitCode const SOFTWARE;

            /// @brief The exit code for a operating system error
            static ExitCode const OSERR;

            /// @brief The exit code for a critical operating system file missing error
            static ExitCode const OSFILE;

            /// @brief The exit code for a can not create output file error
            static ExitCode const CANTCREAT;

            /// @brief The exit code for a IO error
            static ExitCode const IOERR;

            /// @brief The exit code for a temporary failure
            static ExitCode const TEMPFAIL;

            /// @brief The exit code for a remote error in protocol
            static ExitCode const PROTOCOL;

            /// @brief The exit code for a permission denied error
            static ExitCode const NOPERM;

            /// @brief The exit code for a configuration error
            static ExitCode const CONFIG;

        private:
            /// @brief The code of the exit code
            int code;

            /// @brief The description of the exit code
            char const * description;

        private:
            /// @brief Creates a new exit code
            /// @param code The code of the exit code
            /// @param description The description of the exit code
            ExitCode(int code, char const * description) {
                this->code = code;
                this->description = description;
            }

        public:
            /// @brief Gets the code of the exit code
            /// @return The code of the exit code
            int getCode() const;

            /// @brief Gets the description of the exit code
            /// @return The description of the exit code
            char const * getDescription() const;
    };

} // namespace Tobot::Core
