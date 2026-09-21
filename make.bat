@echo off
if "%1"=="" (
    echo Available commands: build, clear
    set /p command="Enter command: "
    goto :execute
) else (
    set command=%1
    goto :execute
)

:execute
if "%command%"=="build" (
    echo Building project...
    node build.js
    goto :eof
)

if "%command%"=="clear" (
    echo Deleting all .code.typ files in src directory...
    del /s /q "src\*.code.typ" 2>nul
    if %errorlevel% equ 0 (
        echo Done! All .code.typ files have been deleted.
    ) else (
        echo No .code.typ files found or an error occurred.
    )
    goto :eof
)

echo Unknown command: %command%
echo Available commands: build, clear
