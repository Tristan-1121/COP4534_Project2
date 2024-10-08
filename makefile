# Makefile for the simulation project

# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files
SRCS = main.cpp simulation.cpp priorityQueue.cpp customer.cpp event.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = simulation

# Input files
INPUT1 = test1.txt
INPUT2 = test2.txt

# Default target
all: $(TARGET) run

# Rule to link the object files
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Rule to run the program
run: $(TARGET)
	./$(TARGET) $(INPUT1) $(INPUT2)

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)









