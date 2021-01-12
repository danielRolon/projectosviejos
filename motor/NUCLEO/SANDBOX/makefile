#BINARY--------------------------------------------------------------
APP := main

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
CCFLAGS     := -Isrc -Wall -pedantic -std=c++17
DEFINES     := -DDG_PLATFORM_WINDOWS

#LIBS
PROJECTDIR   := ..
INCLUDESDIRS := -I$(PROJECTDIR)/QUACK/src/ -I$(PROJECTDIR)/LIBS/GLFW/include/
LIBSDIRS     := -L. -lDUCKGAME             $(PROJECTDIR)/LIBS/GLFW/lib-mingw/libglfw3.a -lgdi32 -lopengl32

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES) $(LIBSDIRS)

$(OBJSUBDIRS): $(SUBDIRS)
	$(MKDIR) $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(DEFINES) $(INCLUDESDIRS)

clean:
	rm -f -r obj/ $(APP)