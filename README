`lslint` is a tool to check the syntactic and semantic validity of Second Life
LSL scripts.

[![Build Status](https://travis-ci.org/Ociidii-Works/lslint.svg?branch=master)](https://travis-ci.org/Ociidii-Works/lslint)

####Compiling
make should be all that's required on POSIX systems, and a solution file exists for VS2015 on Windows



####License
All code is public domain unless otherwise noted.

LSL scripts are from various sources and the property of their respective
owners.

`.l` and `.y` files are based on samples provided by Linden Lab.

**WARNING:** `lslint` faithfully reproduced all the quirks of the LSL compiler circa ~2006,
like having constants as lexer tokens, events as part of the parser grammar,
and lots of right recursion. From a compiler perspective, it does everything
wrong, and is not recommended as a base for anything but a lint tool.

#### Additional changes
#####Makopoppo:
* added nmake support (see NMAkefile for details).
* dropped builtins.txt creator. if you look for new builtins.txt, see [kwdb project](https://bitbucket.org/Sei_Lisa/kwdb)
* enabled appending the input file path to the result lines by "-p".

#####Xenhat
* Makefile-less VS2015 support (more cpp hybridization was necessary)
    * Side effects includes x86_64 binary, x86 is possible still

NOTE ABOUT CODE PAGE:
You may need to change the system locale to "English(US)" for successful compilation.
Use "chcp" command to make sure that the active code page is 437.

####Special Thanks
Strife Onizuka
Howie Lament
Cory Linden
Huns Valen
Doran Zemlja / Adam Wozniak

####Shout Outs
Daniel Linden
Bakuzelas Khan
One Song
Otacon Falcone
Shokra Patel
