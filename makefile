CXX    		:= -g++
CXXFLAGS 	:= -pedantic-errors -Wall -Wextra -Werror -std=c++11
LDFLAGS  	:= -L/usr/lib -lstdc++ -lm
BUILD    	:= $(shell pwd)/build
OBJ_DIR 	:= $(BUILD)/objects
APP_DIR		:= $(shell pwd)
TARGET		:= psr
INCLUDE		:= -Iinclude/
SRC		:= $(wildcard *.C) 
OBJECTS 	:= $(SRC:%.C=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.C
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
