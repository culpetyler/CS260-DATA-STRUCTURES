@ECHO off
ECHO Running CMake build for CS260-DATA-STRUCTURES.
ECHO.
cmake -B ./build -G "Visual Studio 17 2022"
cmake --build ./build --config "Release"
cmake --install ./build --config "Release"
ECHO.
ECHO Finished building and installing CS260-DATA-STRUCTURES.
ECHO.
ECHO Entering binary directory.
ECHO.
ECHO Enter "assignmentX.exe" to run.
ECHO.
cd ./bin
cmd \k