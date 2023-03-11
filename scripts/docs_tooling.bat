:: Generates documentation using doxyxgen (https://www.doxygen.nl/)
@ECHO OFF
IF NOT EXIST ..\packages\tobot_tooling\src (
    ECHO Can not find source directory fo the tobot-tooling
    EXIT
)
cd ..\packages\tobot_tooling\src
ECHO Generating Documentation of the tooling ...
doxygen
ECHO Moving generated content out of the html folder ...
IF NOT EXIST ..\docs\tobot-tooling (
    ECHO Can not find docs directory
    EXIT
)
IF NOT EXIST ..\docs\tobot-tooling\html (
    ECHO Can not find html directory
    EXIT
)
copy ..\docs\tobot-tooling\html ..\docs\tobot-tooling
ECHO Removing html folder ...
rmdir /s ..\docs\tobot-tooling\html\