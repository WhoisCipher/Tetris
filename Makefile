# Directories
SRC_DIR := src
HEADER_DIR := header
ASSETS_DIR := assets
BUILD_DIR := build
RAYLIB_DIR := /home/abdullah/raylib

CXX := g++
CXXFLAGS := -I$(HEADER_DIR) -I$(RAYLIB_DIR)/src -L$(RAYLIB_DIR)/src -Wall -std=c++17
LDFLAGS := -lraylib -lm -ldl -lpthread -lrt -lX11

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

TARGET := tetris.exe

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run