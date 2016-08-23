FLAGS = -Wall -pedantic -std=c++11
DEBUG = -g -ggdb
PROG = maze
OBJ = main.o maze.o mazeGenerator.o cell.o binaryLoad.o binarySave.o svgSave.o

%.o: %.cpp
	g++ $(FLAGS) $(DEBUG) -c $< -o $@

all: $(OBJ)
	g++ -o $(PROG) $(OBJ)

clean:
	rm -f $(OBJ) $(PROG)