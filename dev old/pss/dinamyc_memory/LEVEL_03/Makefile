#BINARY--------------------------------------------------------------
APP := main

#COMPILERS
CC := g++

#COMMANDS
MKDIR := mkd -p

#DIRS
OBJ := obj
SRC := src
SUBDIRS := $(shell findgnu src -type d) 
OBJSUBDIRS := $(patsubst src%,obj%,$(SUBDIRS))

#FILES
CPPFILES := $(shell findgnu src/ -type f -iname *.cpp)
OBJFILES := $(patsubst %.cpp,%.o,$(CPPFILES))

#FLAGS
CCFLAGS := -Wall -pedantic

#PHONY---------------------------------------------------------------
.PHONY: info
.PHONY: run

#DEPENDENCIES--------------------------------------------------------
$(APP): $(OBJSUBDIRS) $(OBJFILES)
	$(CC) -o $(APP) $(patsubst $(SRC)%,$(OBJ)%,$(OBJFILES)) 

$(OBJSUBDIRS): $(SUBDIRS)
	$(MKDIR) $(OBJSUBDIRS)

%.o: %.cpp
	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS) -std=c++14

#LOG
info:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(CPPFILES))
	$(info $(OBJFILES))

#RUN
run:
	./$(APP)
#BUILD
build: $(APP)
	./$(APP)