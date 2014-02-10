PROGRAM = lslint
VERSION_NUMBER = 0.4.2-m1
BUILD_DATE = $(shell date +"%Y-%m-%d")

# See if we're running on windows
UNAME = $(shell uname -a | grep CYGWIN)
ifneq "$(UNAME)" ""
WINDOWS = 1
endif
UNAME = $(shell uname -a | grep Darwin)
ifneq "$(UNAME)" ""
MAC = 1
endif
UNAME = $(shell uname -p | grep powerpc)
ifneq "$(UNAME)" ""
PPC = 1
endif

# Don't run flex or bison on windows.
ifndef WINDOWS
LEX = flex
YACC = bison
else
LEX = echo
YACC = echo
endif


ifndef WINDOWS
DEBUG ?= -DDEBUG_LEVEL=LOG_DEBUG_MINOR -ggdb
else
DEBUG ?= -DDEBUG_LEVEL=LOG_DEBUG_MINOR -Zi
LINKDEBUG = 
ifneq "$(DEBUG)" ""
LINKDEBUG = -DEBUG
endif
endif

ifndef WINDOWS
OPTIMIZE ?= 
CXX = g++ -g -Wall -Wno-write-strings -Wno-non-virtual-dtor -fno-default-inline -fno-omit-frame-pointer -ffloat-store
CXXOUTPUT = -o
ifndef MAC
LD = g++ -g -static
else
ifndef PPC
CXX += -arch i386
LD = g++ -arch i386
else
CXX += -arch i386 -arch ppc
LD = g++ -arch i386 -arch ppc
endif
endif
LDOUTPUT = -o 
UPX = true
else
CXX = cl -W3 -TP -D "WIN32" -D "NDEBUG" -D "_CONSOLE" -D "_MBCS" -D "YY_NO_UNISTD_H" -FD -EHsc -nologo
CXXOUTPUT = -Fo
LD = link $(LINKDEBUG) -INCREMENTAL:NO -NOLOGO -SUBSYSTEM:CONSOLE -OPT:REF -OPT:ICF -MACHINE:X86  # kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib
LDOUTPUT = -OUT:
PROGRAM = lslint.exe
ifneq "$(DEBUG)" ""
UPX = echo
else
UPX = "X:\Program Files\upx\upx" --force --best --crp-ms=999999
endif
endif

CXX += $(DEBUG) $(OPTIMIZE) -DVERSION='"$(VERSION)"' -DBUILD_DATE='"$(BUILD_DATE)"'
CC = $(CXX)

ifneq "$(DEBUG)" ""
VERSION = $(VERSION_NUMBER)debug
else
VERSION = $(VERSION_NUMBER)
endif

OBJS = lslmini.tab.o lex.yy.o lslmini.o symtab.o builtins.o builtins_txt.o types.o values.o final_walk.o operators.o logger.o

$(PROGRAM): $(OBJS)
	$(LD) $(LDOUTPUT)"$@" $^
	$(UPX) "$@"

clean:
	rm -f $(OBJS) lex.yy.c lslint lslmini.tab.c lslmini.tab.h

$(OBJS): lslmini.hh

builtins_txt.cc: builtins.txt
	echo "#ifdef _WIN32" > builtins_txt.cc
	echo "#pragma execution_character_set(\"utf-8\")" >> builtins_txt.cc
	echo "#endif" >> builtins_txt.cc
	echo "char *builtins_txt[] = {" >> builtins_txt.cc
	cat builtins.txt | \
		sed "s/\"/\\\\\\\"/g" | \
		sed "s/^/\"/g" | \
		sed "s/$$/\",/g" >> builtins_txt.cc
	echo "(char*)0 };" >> builtins_txt.cc

lex.yy.o: lex.yy.c lslmini.tab.h

lex.yy.o lslmini.tab.o lslmini.o symtab.o builtins.o: lslmini.hh symtab.hh ast.hh types.hh

logger.o: lslmini.tab.h logger.hh

types.o: types.hh lslmini.hh

lslmini.tab.c lslmini.tab.h: lslmini.y
	$(YACC) -d lslmini.y

lex.yy.c: lslmini.l
	$(LEX) lslmini.l

.c.o .cc.o:
	$(CXX) $(CXXOUTPUT)"$@" -c $<
