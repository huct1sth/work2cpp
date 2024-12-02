@echo off
cd /d C:\Users\20486\Desktop\cpp-training
echo [DEBUG] Switched to project root: %cd%

call script\build.bat
echo [DEBUG] Build process errorlevel: %errorlevel%
if %errorlevel% neq 0 (
    echo [ERROR] Build process failed.
    pause
    exit /b 1
)

call script\run.bat
echo [DEBUG] Run process errorlevel: %errorlevel%
if %errorlevel% neq 0 (
    echo [ERROR] Run process failed.
    pause
    exit /b 1
)

echo [SUCCESS] Build and run completed successfully!
pause