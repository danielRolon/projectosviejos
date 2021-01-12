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
CCFLAGS     := -Isrc -std=c++17
DEFINES     := -DGLEW_STATIC
#LIBS
PROJECTDIR   := ..
INCLUDESDIRS := -Isrc/ -Isrc/vendor/ -ILIBS/GLFW/include/ -ILIBS/GLEW/include/ 
LIBSDIRS     := LIBS/GLFW/lib-mingw/libglfw3.a LIBS/GLEW/lib/Release/Win32/glew32s.lib -lgdi32 -lopengl32 -limm32

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: $(OBJSUBDIRS)
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES) $(LIBSDIRS)

$(OBJSUBDIRS): $(SUBDIRS)
	mkdir -p $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(DEFINES) $(INCLUDESDIRS)

clean:
	rm -f -r obj/ $(APP)