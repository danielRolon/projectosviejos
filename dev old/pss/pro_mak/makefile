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

#LIBS
INCLUDE_PATHS   := -Isrc/
LIBRARY_PATHS   := 

#FLAGS
COMPILER_CFLAGS := -std=c++17
LINKER_CFLAGS   :=

#PHONY---------------------------------------------------------------
.PHONY: info

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES) $(LIBRARY_PATHS) $(LINKER_CFLAGS)

$(OBJSUBDIRS): $(SUBDIRS)
	mkdir -p $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(INCLUDE_PATHS) $(COMPILER_CFLAGS)

clean:
	rm -f -r obj/ $(APP)

cleansrc:
	rm -f -r src/
	mkdir -p src/