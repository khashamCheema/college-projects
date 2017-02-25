all: main

node.o: node.h node.cpp
	g++ -c -std=c++0x -g node.cpp

bst.o: bst.h bst.cpp
	g++ -c -std=c++0x -g bst.cpp

main.o: main.cpp
	g++ -c -std=c++0x -g main.cpp

main: node.o bst.o main.o
	g++ -g -std=c++0x node.o bst.o main.o -o main

clean: 
	rm *.o *~ main