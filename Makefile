# Directories
SRC_DIR := src
HEADER_DIR := header
ASSETS_DIR := assets
BUILD_DIR := build
RAYLIB_DIR := ~/raylib_projects

# Compiler and linker
CXX := g++
CXXFLAGS := -I$(HEADER_DIR) -I$(RAYLIB_DIR)/src -L$(RAYLIB_DIR)/src -Wall -std=c++17
LDFLAGS := -lraylib -lm -ldl -lpthread -lrt -lX11

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Output executable
TARGET := tetris.exe

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
