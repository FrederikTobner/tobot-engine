#pragma once

namespace Tobot::Core {
    class ExitCode {
        public:
            static const ExitCode OK;
            static const ExitCode CommandLineUsageError;
            static const ExitCode SubSystemError;
            static const ExitCode IOError;

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
