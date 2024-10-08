# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets
TARGET = simulation
OBJECTS = main.o simulation.o priorityQueue.o FIFOQueue.o customer.o event.o

# Build and run target
all: $(TARGET)
	./$(TARGET)

# Linking the object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean target to remove generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

