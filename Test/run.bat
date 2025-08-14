@echo off
setlocal

:: Kiểm tra tham số
if "%~1"=="" (
    echo Usage: run.bat [test_<number>] [/rebuild] [/debug]
    exit /b 1
)
set "TEST_FOLDER=%~1"
set "REBUILD=%~2"
set "DEBUG=%~3"

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

:: Nếu không phải rebuild thì check timestamp
if /i not "%REBUILD%"=="/rebuild" (
    if exist "%TEST_OUTPUT%" (
        for %%A in ("%TEST_PATH_FULL%") do for %%B in ("%TEST_OUTPUT%") do (
            if "%%~tB" GEQ "%%~tA" (
                echo Skipping compile: %TEST_OUTPUT% is up to date.
                goto run
            )
        )
    )
)

:compile
echo Compiling %TEST_FILE% in %TEST_FOLDER%...
if /i "%DEBUG%"=="/debug" (
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

:: Nếu option /debug được truyền → chạy DrMemory
if /i "%DEBUG%"=="/debug" (
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
