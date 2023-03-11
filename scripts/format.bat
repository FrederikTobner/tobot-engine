:: Formats specific parts of the library.

:: .clang-format is automatically picked up by the npm package. 
:: We should maybe check first if the clang-format npm package is installed at all.

@ECHO OFF
IF NOT EXIST ..\packages\tobot_core\src (
    ECHO Can not find source directory
    EXIT
)

IF NOT EXIST ..\.clang-format (
    ECHO Can not find source directory
    EXIT
)

ECHO Formatting header files src\core

CALL clang-format --glob=..\packages\tobot_core\src\core\*.h -i

ECHO Formatting header files src\include

CALL clang-format --glob=..\packages\tobot_core\src\include\*.h -i

ECHO Formatting header files src\math

CALL clang-format --glob=..\packages\tobot_core\src\math\*.h -i

ECHO Formatting header files src\utilities

CALL clang-format --glob=..\packages\tobot_core\src\utilities\*.h -i

ECHO Formatting header files src\widget

CALL clang-format --glob=..\packages\tobot_core\src\widget\*.h -i

ECHO Formatting entry_point.h

CALL clang-format --glob=..\packages\tobot_core\src\entry_point.h -i

ECHO Formatting example headers...

CALL clang-format --glob=..\packages\tobot_core\example\*.h -i

ECHO Formatting example sources...

CALL clang-format --glob=..\packages\tobot_core\example\*.cpp -i