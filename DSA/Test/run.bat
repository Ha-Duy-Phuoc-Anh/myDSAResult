@echo off
setlocal enabledelayedexpansion

:: Kiểm tra tham số
if "%~1"=="" (
    echo Usage: run.bat [test_<number>] [/debug|/release]
    exit /b 1
)

set "TEST_FOLDER=%~1"
set "BUILD_MODE=%~2"

if /i not "%BUILD_MODE%"=="/debug" if /i not "%BUILD_MODE%"=="/release" (
    echo Error: second argument must be /debug or /release
    exit /b 1
)

set "TEST_OUTPUT=%~dp0build\%TEST_FOLDER%\test.exe"

if not exist "%~dp0build\%TEST_FOLDER%" (
    mkdir "%~dp0build\%TEST_FOLDER%"
)

:: Tìm tất cả các file .cpp trong thư mục test
set "CPP_FILES="
for %%f in ("%~dp0%TEST_FOLDER%\*.cpp") do (
    set "CPP_FILES=!CPP_FILES! %%f"
)

:compile
echo Compiling all .cpp files in %TEST_FOLDER% (%BUILD_MODE%)...
if /i "%BUILD_MODE%"=="/debug" (
    cl.exe /Od /EHsc /Zi /MDd /fsanitize=address !CPP_FILES! /Fe:"%TEST_OUTPUT%"
) else (
    cl.exe /O2 /GL /Gy /Oi /arch:AVX2 /favor:blend /EHsc /Zi !CPP_FILES! /link /LTCG /OPT:REF /OPT:ICF /INCREMENTAL:NO /OUT:"%TEST_OUTPUT%"
)

if errorlevel 1 (
    echo Compilation failed!
    exit /b 1
)

:run 
"%TEST_OUTPUT%"
echo.

:: Cleanup thông minh
echo Cleaning up old files...
del /Q "%~dp0build\%TEST_FOLDER%\*.pdb" 2>nul
del /Q "%~dp0build\%TEST_FOLDER%\*.ilk" 2>nul
del /Q "%~dp0build\%TEST_FOLDER%\*.obj" 2>nul
del /Q "%~dp0build\%TEST_FOLDER%\*.exp" 2>nul
del /Q "%~dp0build\%TEST_FOLDER%\*.lib" 2>nul

:: Xoá file tạm ngoài root (nếu có)
del /Q "%~dp0*.obj" 2>nul
del /Q "%~dp0*.pdb" 2>nul

endlocal
