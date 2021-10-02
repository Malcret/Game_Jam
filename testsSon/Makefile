OS = linux
BUILD_MOD = debug
CXX_VERSION = c++20
PROG_NAME = prog

INC_DIR = -I./include
LIB_DIR = -L./lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/user/visualStudio/testsSon/lib
ifeq ($(OS), linux)
LIB_FILES = -lIrrKlang -pthread
else ifeq ($(OS), win32)
LIB_FILES =
else
@echo Wrong OS, use 'linux' or 'win32'
endif

ifeq ($(BUILD_MOD), debug)
CXX_FLAGS = -std=$(CXX_VERSION) -g -Og -Wall
else ifeq ($(BUILD_MOD), release)
CXX_FLAGS = -std=$(CXX_VERSION) -O2 -DNDEBUG
else
@echo Wrong build mod, use 'debug' or 'release'
endif

SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, bin/$(OS)/$(BUILD_MOD)/obj/%.o, $(SRC_FILES))
PROG = bin/$(OS)/$(BUILD_MOD)/$(PROG_NAME)

bin/$(OS)/$(BUILD_MOD)/obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	g++ $(CXX_FLAGS) $(INC_DIR) -o $@ -c $<

$(PROG): $(OBJ_FILES)
	g++ $(LIB_DIR) -o $@ $^ $(LIB_FILES)

.PHONY: build run clean mrproper help

build: $(PROG)

run:
	cd bin/$(OS)/$(BUILD_MOD)/ && ./$(PROG_NAME)

clean:
	rm -Rf bin/$(OS)/$(BUILD_MOD)/*.o
	rm -Rf $(PROG)

mrproper:
	rm -Rf bin/*

help:
	@echo "'build' to build your code"
	@echo "'run' to run your program"
	@echo "'clean' to remove all object files associate to your build mod"
	@echo "'mrproper' to remove your 'build' directory"

