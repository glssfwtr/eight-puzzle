CXX = g++

CXXFLAGS = -Ofast -ffast-math -flto -fomit-frame-pointer\
							-ftree-vectorize -funroll-loops -march=native -mavx2\
							-Wall -Wcast-align -Wcast-qual -Wconversion\
							-Wdisabled-optimization -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond\
							-Wextra -Wfloat-equal -Wformat=2 -Wlogical-op\
							-Wmisleading-indentation -Wmissing-include-dirs -Wnon-virtual-dtor -Wnull-dereference\
							-Wold-style-cast -Woverloaded-virtual -Wpedantic -Wpointer-arith\
							-Wshadow -Wsign-conversion -Wstrict-aliasing -Wstrict-overflow\
							-Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code\
							-Wunused -Wuseless-cast -Wvla\

SOURCES = $(wildcard *.cpp *.hpp)

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = a.out

all: clean $(EXECUTABLE)
			@./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(DEPS) $(EXECUTABLE)