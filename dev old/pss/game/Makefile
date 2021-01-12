#BINARY--------------------------------------------------------------
APP := bin/main

#COMPILERS
CC := g++

#COMMANDS
MKDIR := mkdir -p

#DIRS
OBJ := obj
SRC := src
BIN := bin
SUBDIRS := $(shell findgnu src -type d) 
OBJSUBDIRS := $(patsubst src%,obj%,$(SUBDIRS))

#FILES
CPPFILES := $(shell findgnu src/ -type f -iname *.cpp)
OBJFILES := $(patsubst $(SRC)%,$(OBJ)%,$(patsubst %.cpp,%.o,$(CPPFILES)))

#FLAGS
CCFLAGS := -I./src -std=gnu++14 -O3 #-Wall -pedantic

#DEPENCIES
LIBDIR := dependecies
LIBSDIRS := $(LIBDIR)/PDCURSES/wincon/pdcurses.a
INCLUDEDIRS := -I./$(LIBDIR)/PDCURSES/

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(BIN) $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES) $(LIBSDIRS)

$(BIN):
	$(MKDIR) $(BIN)

$(OBJSUBDIRS): $(SUBDIRS)
	$(MKDIR) $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS) $(INCLUDEDIRS)

#LOG
info:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(CPPFILES))
	$(info $(OBJFILES))

clean:
	rm -f -r $(OBJFILES) $(APP)

run:
	./$(APP)

build_run: $(APP) 
	./$(APP)