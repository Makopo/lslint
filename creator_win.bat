set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile 
move lslint.exe binary\windows
nmake /F NMakefile clean
