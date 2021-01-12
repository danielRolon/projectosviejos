#BINARY--------------------------------------------------------------
APP := DUCKGAME.dll

#COMPILERS
CC := g++

#COMMANDS
MKDIR := mkdir -p

#DIRS
OBJ := obj
SRC := src
SUBDIRS := $(shell findgnu src -type d) 
OBJSUBDIRS := $(patsubst src%,obj%,$(SUBDIRS))


#FILES
CPPFILES := $(shell findgnu src/ -type f -iname *.cpp)
OBJFILES := $(patsubst $(SRC)%,$(OBJ)%,$(patsubst %.cpp,%.o,$(CPPFILES)))

#FLAGS
CCFLAGS := -Isrc -Wall -pedantic -std=c++17
DEFINES := -DDG_PLATFORM_WINDOWS -DDG_BUILD_DLL

#LIBS
PROJECTDIR   := ..
INCLUDESDIRS := -I$(PROJECTDIR)/LIBS/GLFW/include/
LIBSDIRS     := $(PROJECTDIR)/LIBS/GLFW/lib-mingw/libglfw3.a

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -shared -o $(APP) $(OBJFILES) $(LIBSDIRS)

$(OBJSUBDIRS): $(SUBDIRS)
	$(MKDIR) $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(DEFINES) $(INCLUDESDIRS)

#LOG
info:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(CPPFILES))
	$(info $(OBJFILES))

clean:
	rm -f -r obj/ $(APP)