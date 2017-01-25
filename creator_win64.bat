call "C:\Program Files (x86)\Microsoft Visual studio 14.0\VC\vcvarsall.bat" amd64
set PATH=%PATH%;C:\flexandbison
nmake /F NMakefile 
move lslint.exe binary\windows\32
nmake /F NMakefile clean
