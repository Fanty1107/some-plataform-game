# Name of the final executable
TARGET = plataform

# Compiler and Flags
CC      = clang++
CFLAGS  = -Wall -Wextra -pedantic
LDFLAGS = 

# Build configurations
DEBUG_FLAGS   = -g3 -O0 -DDEBUG
RELEASE_FLAGS = -O3 -DNDEBUG

# Directories
SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = .

# Automatically find all .c files in SRC_DIR and map them to object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# External Libraries & Include paths (uncomment and adjust as needed)
# Example for Raylib: LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
# Example using pkg-config: LIBS = $(shell pkg-config --libs sdl3)
LIBS     = -lraylib -lGL -lm -lpthread -ldl -lrt 
INCLUDES = -Iinclude

# -----------------------------------------------------------------------------
# Targets
# -----------------------------------------------------------------------------

# Default target: Debug build
all: CFLAGS += $(DEBUG_FLAGS)
all: $(BIN_DIR)/$(TARGET)

# Release target: Optimized build with debugging info stripped
release: CFLAGS += $(RELEASE_FLAGS)
release: clean $(BIN_DIR)/$(TARGET)

# Linking the final executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)
	@echo "Built target: $(TARGET)"

# Compiling source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Run the compiled binary
run: all
	@./$(BIN_DIR)/$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)/$(TARGET)
	@echo "Cleaned build artifacts."

# Declare phony targets
.PHONY: all release run clean
