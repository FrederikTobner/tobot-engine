:: Generates documentation using doxyxgen (https://www.doxygen.nl/)
@ECHO OFF
IF NOT EXIST ..\packages\tobot_math\src (
    ECHO Can not find source directory fo the tobot-math
    EXIT
)
cd ..\packages\tobot_math\src
ECHO Generating Documentation of the math ...
doxygen
ECHO Moving generated content out of the html folder ...
IF NOT EXIST ..\docs\tobot-math (
    ECHO Can not find docs directory
    EXIT
)
IF NOT EXIST ..\docs\tobot-math\html (
    ECHO Can not find html directory
    EXIT
)
copy ..\docs\tobot-math\html ..\docs\tobot-math
ECHO Removing html folder ...
rmdir /s ..\docs\tobot-math\html\