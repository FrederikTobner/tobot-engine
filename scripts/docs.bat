:: Generates documentation using doxyxgen (https://www.doxygen.nl/) for a single project
IF "%1" == ""(set \p projectName=Project to document :) else (set projectName=%1)
@ECHO OFF
IF NOT EXIST ..\packages\%projectName%\src (
    ECHO Can not find source directory
    EXIT 74
)
cd ..\packages\%projectName%\src
ECHO Generating Documentation ...
doxygen
ECHO Moving generated content out of the html folder ...
IF NOT EXIST ..\..\..\docs\%projectName%\ (
    ECHO Can not find docs directory
    EXIT 74
)
IF NOT EXIST ..\..\..\docs\%projectName%\html (
    ECHO Can not find html directory
    EXIT 74
)
xcopy ..\..\..\docs\%projectName%\html ..\..\..\docs\%projectName% /E
ECHO Removing html folder ...
rmdir /s ..\..\..\docs\%projectName%\html\
cd ..\..\..\scripts
EXIT 0