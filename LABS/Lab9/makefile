all: run

run: RBT.o BST.o main.o timer.o
	g++ -std=c++11 RBT.o BST.o main.o timer.o -o run

RBT.o: RBT.cpp
	g++ -std=c++11 -c RBT.cpp

BST.o: BST.cpp
	g++ -std=c++11 -c BST.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

timer.o: timer.cpp
	g++ -std=c++11 -c timer.cpp

clean:
	rm -rf *.o run
