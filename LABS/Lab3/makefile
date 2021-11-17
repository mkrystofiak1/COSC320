all: run

run: Heap.o  Lab3.o
	g++ -g Heap.o Lab3.o -o run

Heap.o: Heap.cpp
	g++ -c -g Heap.cpp

Lab3.o: Lab3.cpp
	g++ -c -g Lab3.cpp

clean:
	rm -rf *.o run

