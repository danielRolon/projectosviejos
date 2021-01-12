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
CCFLAGS := -Isrc -Wall -pedantic -std=c++17

#PHONY---------------------------------------------------------------
.PHONY: info
#.PHONY: clean

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(OBJFILES)

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

rebuild: clean $(APP)

run:
	./$(APP)

build_run: $(APP) 
	./$(APP)