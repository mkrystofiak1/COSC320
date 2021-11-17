all: run

run: Lab4.o
	g++ -std=c++11 Lab4.o -o run

Lab4.o: Lab4.cpp HeapQ.h HeapQ.cpp
	g++ -std=c++11 -c Lab4.cpp

clean:
	rm -rf *.o run


