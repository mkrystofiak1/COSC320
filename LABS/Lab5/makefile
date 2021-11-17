all: run

run: Lab5.o Matrix.o
	g++ -std=c++11 Lab5.o Matrix.o -o run

Lab5.o: Lab5.cpp
	g++ -std=c++11 -c Lab5.cpp

Matrix.o: Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm -rf *.o run
