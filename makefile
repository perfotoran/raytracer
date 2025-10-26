.PHONY: all clean prep debug release remake
CXX = g++

CFLAGS = -std=c++14 -Wall -pedantic -I./src
LDFLAGS =
LDLIBS =

BIN_NAME = main
SYS_DIR = /usr/local
SRC_DIR = ./src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)


DEBUG_DIR = debug
DEBUG_BIN = $(DEBUG_DIR)/$(BIN_NAME)
DEBUG_OBJ_DIR = $(DEBUG_DIR)/obj
DEBUG_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(DEBUG_OBJ_DIR)/%.o, $(SOURCES))
DEBUG_FLAGS = -g -O0 -DDEBUG


RELEASE_DIR = release
RELEASE_BIN = $(RELEASE_DIR)/$(BIN_NAME)
RELEASE_OBJ_DIR = $(RELEASE_DIR)/obj
RELEASE_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(RELEASE_OBJ_DIR)/%.o, $(SOURCES))
RELEASE_FLAGS = -O3 -DNDEBUG -s



all: debug

debug: prep $(DEBUG_BIN) 

$(DEBUG_BIN): $(DEBUG_OBJS)
	$(CXX) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(DEBUG_FLAGS) -o $@ $< 



release: prep $(RELEASE_BIN)

$(RELEASE_BIN): $(RELEASE_OBJS)
	$(CXX) $(CFLAGS) $(RELEASE_FLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(RELEASE_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(RELEASE_FLAGS) -o $@ $< 

remake: clean debug


tests: debug
	$(CXX) $(CFLAGS) ./tests/test*.cpp $(filter-out $(DEBUG_OBJ_DIR)/main.o, $(DEBUG_OBJS)) -o test -lgtest -lgtest_main

prep:
	mkdir -p $(DEBUG_DIR) $(DEBUG_OBJ_DIR) $(RELEASE_DIR) $(RELEASE_OBJ_DIR)

clean:
	rm -rf $(DEBUG_DIR) $(RELEASE_DIR)