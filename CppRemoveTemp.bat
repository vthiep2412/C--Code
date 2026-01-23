@echo off
set "TARGET_DIR=C:\Users\vthie\.VScode\Hiep Code"

if exist "%TARGET_DIR%" (
    del /s /q "%TARGET_DIR%\*.exe"
    @REM del /s /q "%TARGET_DIR%\*.inp"
    del /s /q "%TARGET_DIR%\*.out"
    echo All .exe, .inp, and .out files removed from %TARGET_DIR%
) else (
    echo Directory %TARGET_DIR% does not exist.
)
pause