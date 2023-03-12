:: Generates documentation using doxyxgen (https://www.doxygen.nl/)
@ECHO OFF
IF NOT EXIST ..\packages\tobot_core\src (
    ECHO Can not find source directory fo the tobot-core
    EXIT
)
cd ..\packages\tobot_core\src
ECHO Generating Documentation of the core ...
doxygen
ECHO Moving generated content out of the html folder ...
IF NOT EXIST ..\docs\tobot-core (
    ECHO Can not find docs directory
    EXIT
)
IF NOT EXIST ..\docs\tobot-core\html (
    ECHO Can not find html directory
    EXIT
)
copy ..\docs\tobot-core\html ..\docs\tobot-core
ECHO Removing html folder ...
rmdir /s ..\docs\tobot-core\html\