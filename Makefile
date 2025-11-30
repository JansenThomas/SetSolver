CXX = g++
CXXFLAGS = -Iexternal/SDL/include

ifeq ($(wildcard external/SDL/build/libSDL3.a),external/SDL/build/libSDL3.a)
    LDFLAGS = external/SDL/build/libSDL3.a -ldl -lpthread -lm
else
    LDFLAGS = -Lexternal/SDL/build -lSDL3 -ldl -lpthread -lm
endif


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
