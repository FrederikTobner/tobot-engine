:: Deletes all the files stored in the logs folder
@ECHO OFF
IF NOT EXIST ..\logs (
    ECHO Can not find logs directory
    EXIT
)
DEL "..\logs\*.*?"