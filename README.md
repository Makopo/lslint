`lslint` is a tool to check the syntactic and semantic validity of Second Life LSL scripts.

[![Makopo](https://circleci.com/gh/Makopo/lslint.svg?style=svg)](https://app.circleci.com/pipelines/github/Makopo/lslint)

#### Releases

See [Releases](https://github.com/Makopo/lslint/releases) for binaries.
Latest release resides [here](https://github.com/Makopo/lslint/releases/latest).

#### Compiling
* `make` should be all that's required on POSIX systems, and a solution file exists for VS2015 on Windows.
* [Win flex-bison](http://sourceforge.net/projects/winflexbison/) as well as VS2015 or [SDK7.0](https://www.microsoft.com/download/details.aspx?id=3138) or later are required for Windows build. See the comment in [NMakefile](NMakefile) for detailed instructions.

#### License
All code is public domain unless otherwise noted.

LSL scripts are from various sources and the property of their respective owners.

`.l` and `.y` files are based on samples provided by Linden Lab.

**WARNING:** `lslint` faithfully reproduced all the quirks of the LSL compiler circa ~2006,
like having constants as lexer tokens, events as part of the parser grammar,
and lots of right recursion. From a compiler perspective, it does everything
wrong, and is not recommended as a base for anything but a lint tool.

#### Additional changes
##### Makopoppo
* added nmake support (see NMAkefile for details).
* dropped builtins.txt creator. if you look for new builtins.txt, see [kwdb project](https://github.com/Sei-Lisa/kwdb)
* enabled appending the input file path to the result lines by "-p".

##### Xenhat
* Makefile-less VS2015 support (more cpp hybridization was necessary)
    * Side effects includes x86_64 binary, x86 is possible still

##### Sei-Lisa
* added Mono mode (-m for Mono(default), -m- for LSO)
* added option to make the warning on unused event parameters optional (-u to enable, -u- to disable)
* added option to ignore preprocessor commands (-i)
* added switch() statement and lazy list support
* added god mode support
* added reporting of several errors and warnings
* numerous bug fixes and enhancements

#### Special Thanks
* Strife Onizuka
* Howie Lament
* Cory Linden
* Huns Valen
* Doran Zemlja / Adam Wozniak

#### Shout Outs
* Daniel Linden
* Bakuzelas Khan
* One Song
* Otacon Falcone
* Shokra Patel
