@echo off

set ARG1=%1

if "%ARG1%"=="release" goto :Release
if "%ARG1%"=="debug" goto :Debug

echo Tipe build tidak valid
goto :End

:Release
echo Formating...
for /r %%i in (src include) do (
    if "%%~xi"==".h" echo Formatting: %%i & clang-format -i "%%i"
    if "%%~xi"==".cpp" echo Formatting: %%i & clang-format -i "%%i"
    if "%%~xi"==".cc" echo Formatting: %%i & clang-format -i "%%i"
)
echo Configuration...
cmake --preset %ARG1%
echo Building...
cmake --build --preset %ARG1%
echo Copy compile_commands.json
copy build\release\compile_commands.json .\
echo Running...
.\build\release\nusantara
goto :End

:Debug
echo Formating...
for /r %%i in (src include) do (
    if "%%~xi"==".h" echo Formatting: %%i & clang-format -i "%%i"
    if "%%~xi"==".cpp" echo Formatting: %%i & clang-format -i "%%i"
    if "%%~xi"==".cc" echo Formatting: %%i & clang-format -i "%%i"
)
echo Configuration...
cmake --preset %ARG1%
echo Building...
cmake --build --preset %ARG1%
echo Copy compile_commands.json
copy build\debug\compile_commands.json .\
echo Running...
.\build\debug\nusantara
goto :End

:End