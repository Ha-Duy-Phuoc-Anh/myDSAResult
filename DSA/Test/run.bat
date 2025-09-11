@echo off
setlocal enabledelayedexpansion

:: Kiểm tra tham số
if "%~1"=="" (
    echo Usage: run.bat [test_<number>]
    exit /b 1
)

set "TEST_FOLDER=%~1"

:run 
python "%TEST_OUTPUT%"
echo.



endlocal
