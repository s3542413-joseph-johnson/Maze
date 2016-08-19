FLAGS = -Wall -pedantic
DEBUG = -g -ggdb
PROG = maze
OBJ = main.o maze.o mazeGenerator.o edge.o cell.o binaryLoad.o binarySave.o

%.o: %.cpp
	g++ $(FLAGS) $(DEBUG) -c $< -o $@

all: $(OBJ)
	g++ -o $(PROG) $(OBJ)

clean:
	rm -f $(OBJ) $(PROG)