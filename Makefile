CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -Wall -Wextra -std=c++17
TARGET = main
SOURCES = main.cpp Hp.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean $(TARGET)

# Mark these as phony targets
.PHONY: clean rebuild

# Dependencies
main.o: main.cpp allclasses.h
Hp.o: Hp.cpp Hp.h hitpointtypes.h
