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
CCFLAGS := -I./src -std=gnu++17 #-Wall -pedantic

#DEPENCIES
LIBDIR := dependecies
LIBSDIRS := -L. -l$(LIBDIR)/allegro5/bin/allegro-5.0.10-monolith-mt-debug -l$(LIBDIR)/allegro5/bin/allegro-5.0.10-monolith-mt
INCLUDEDIRS := -I$(LIBDIR)/allegro5/include/

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