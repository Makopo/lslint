@echo off
rem :: rem :: VS2015
rem :: IF EXIST "C:\Program Files (x86)\Microsoft Visual studio 14.0\VC\vcvarsall.bat" (
rem ::     call "C:\Program Files (x86)\Microsoft Visual studio 14.0\VC\vcvarsall.bat" x86
rem :: ) else (
rem ::     rem :: VS2017
rem ::     rem :: NOTE: The instructions contained in the NMakefile are no longer necessary with this method.
rem ::     rem :: Simply run the script, as long as C:\flexandbison exists.
rem ::     pushd "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\"
rem ::     call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
rem ::     popd
rem :: )
set VERSION_NUMBER=1.1.1
set BUILD_DATE=%DATE:~-10,4%-%DATE:~-5,2%-%DATE:~-2,2%
set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile
mkdir binary\windows32\
move lslint.exe binary\windows32\
nmake /F NMakefile clean
