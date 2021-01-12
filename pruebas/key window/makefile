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
CCFLAGS     := -std=c++17
DEFINES     :=

#LIBS
INCLUDESDIRS := -Isrc/
LIBSDIRS     :=

#PHONY---------------------------------------------------------------
.PHONY: info

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES) $(LIBSDIRS)

$(OBJSUBDIRS): $(SUBDIRS)
	mkdir -p $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(DEFINES) $(INCLUDESDIRS)

clean:
	rm -f -r obj/ $(APP)