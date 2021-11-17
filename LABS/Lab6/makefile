all: run

run: hiring.o Heap.o sortingAlgorithms.o
	g++ -std=c++11 hiring.o Heap.o sortingAlgorithms.o -o run

hiring.o: hiring.cpp
	g++ -std=c++11 -c hiring.cpp

Heap.o: Heap.cpp
	g++ -std=c++11 -c Heap.cpp

sortingAlgorithms.o: sortingAlgorithms.cpp
	g++ -std=c++11 -c sortingAlgorithms.cpp

clean:
	rm -rf *.o run

