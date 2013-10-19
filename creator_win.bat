call setenv /Release /x86 /xp
set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile 
move lslint.exe binary\windows
nmake /F NMakefile clean
