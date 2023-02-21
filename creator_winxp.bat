call setenv /Release /x86 /xp
set VERSION_NUMBER=1.1.1
set BUILD_DATE=%DATE:~-10,4%-%DATE:~-5,2%-%DATE:~-2,2%
set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile
mkdir binary\windows\
move lslint.exe binary\windows\
nmake /F NMakefile clean
