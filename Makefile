# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Executable name
TARGET = game

# Source files
SRCS = Player.cpp DorN.cpp Login.cpp Dice.cpp Hand.cpp BJ.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rebuild target
rebuild: clean all

# Rebuild target for Linux
rebuild-lin: clean-lin all

# Clean target
clean:
	del -f $(OBJS) $(TARGET).exe

# Clean target for Linux
clean-lin:
	rm -f $(OBJS) $(TARGET).exe
