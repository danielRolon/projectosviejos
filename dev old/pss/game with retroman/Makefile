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
								  
#FLAGS                            #-std=c++17 #-std=gnu++17
CCFLAGS := -I./src -Wall -pedantic -std=gnu++17 -O3

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(BIN) $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES)

$(BIN):
	$(MKDIR) $(BIN)

$(OBJSUBDIRS): $(SUBDIRS)
	$(MKDIR) $(OBJSUBDIRS)

obj/%.o: src/%.cpp
	$(CC) -o $@ -c $^ $(CCFLAGS)

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