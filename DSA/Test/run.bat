@echo off
setlocal

:: Kiểm tra tham số
if "%~1"=="" (
    echo Usage: run.bat [test_<number>] [/debug|/release]
    exit /b 1
)

set "TEST_FOLDER=%~1"
set "BUILD_MODE=%~2"

:: Kiểm tra BUILD_MODE hợp lệ
if /i not "%BUILD_MODE%"=="/debug" if /i not "%BUILD_MODE%"=="/release" (
    echo Error: second argument must be /debug or /release
    exit /b 1
)

:: Tên file test cố định
set "TEST_FILE=test.cpp"

:: Full path file source
set "TEST_PATH_FULL=%~dp0%TEST_FOLDER%\%TEST_FILE%"

:: Đường dẫn output exe
set "TEST_OUTPUT=%~dp0build\%TEST_FOLDER%\test.exe"

:: Tạo thư mục source nếu chưa có
if not exist "%~dp0%TEST_FOLDER%" (
    echo Creating source folder "%TEST_FOLDER%"
    mkdir "%~dp0%TEST_FOLDER%"
)

:: Tạo file test.cpp nếu chưa có
if not exist "%TEST_PATH_FULL%" (
    echo Creating file "%TEST_PATH_FULL%"
    echo // Auto-generated empty test.cpp > "%TEST_PATH_FULL%"
)

:: Tạo thư mục build\<TEST_FOLDER> nếu chưa có
if not exist "%~dp0build\%TEST_FOLDER%" (
    echo Creating build folder: build\%TEST_FOLDER%
    mkdir "%~dp0build\%TEST_FOLDER%"
)

:compile
echo Compiling %TEST_FILE% in %TEST_FOLDER% (%BUILD_MODE%)...
if /i "%BUILD_MODE%"=="/debug" (
    cl.exe /Od /EHsc /Zi /MDd "%TEST_PATH_FULL%" /Fe:"%TEST_OUTPUT%"
) else (
    cl.exe /O2 /GL /Gy /Oi /arch:AVX2 /favor:blend /EHsc /Zi "%TEST_PATH_FULL%" /link /LTCG /OPT:REF /OPT:ICF /INCREMENTAL:NO /OUT:"%TEST_OUTPUT%"
)

if errorlevel 1 (
    echo Compilation failed!
    exit /b 1
)

:run
echo Running program...
if /i "%BUILD_MODE%"=="/debug" (
    echo Running under Dr. Memory...
    drmemory -batch "%TEST_OUTPUT%"
) else (
    "%TEST_OUTPUT%"
)

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
