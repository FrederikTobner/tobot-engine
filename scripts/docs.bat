:: Generates documentation using doxyxgen (https://www.doxygen.nl/)
set projectName=%1
@ECHO OFF
IF NOT EXIST ..\packages\%projectName%\src (
    ECHO Can not find source directory
    EXIT
)
cd ..\packages\%projectName%\src
ECHO Generating Documentation ...
doxygen
ECHO Moving generated content out of the html folder ...
IF NOT EXIST ..\..\..\docs\%projectName%\ (
    ECHO Can not find docs directory
    EXIT
)
IF NOT EXIST ..\..\..\docs\%projectName%\html (
    ECHO Can not find html directory
    EXIT
)
xcopy ..\..\..\docs\%projectName%\html ..\..\..\docs\%projectName% /E
ECHO Removing html folder ...
rmdir /s ..\..\..\docs\%projectName%\html\
cd ..\..\..\scripts