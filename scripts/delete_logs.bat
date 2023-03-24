:: Deletes all the files stored in the logs folder
@ECHO OFF
IF NOT EXIST ..\logs (
    ECHO Can not find logs directory
    EXIT 74
)
DEL "..\logs\*.*?"
EXIT 0