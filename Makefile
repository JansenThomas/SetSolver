# CXX = g++

# CXXFLAGS = -I/usr/include/SDL2 -lSDL2
# SOURCES = main.cpp Solver.cpp World.cpp
# OBJECTS = $(SOURCES:.cpp=.o)
# TARGET = my_program

# all: $(TARGET)

# $(TARGET): $(OBJECTS)
# 	$(CXX) -o $@ $^ $(CXXFLAGS)

# %.o: %.cpp
# 	$(CXX) -c $< -o $@

# clean:
# 	rm -f $(OBJECTS) $(TARGET)

# .PHONY: all clean



CXX = g++
CXXFLAGS = -Iexternal/SDL/include
LDFLAGS = external/SDL/build/libSDL3.a -ldl -lpthread -lm

SOURCES = main.cpp Solver.cpp World.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
