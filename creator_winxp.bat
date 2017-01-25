call setenv /Release /x86 /xp
set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile 
move lslint.exe binary\windows\XP32
nmake /F NMakefile clean
