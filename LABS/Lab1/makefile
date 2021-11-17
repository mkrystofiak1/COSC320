all: run

run: sortingAlgorithms.o  sortLarge.o
	g++ sortingAlgorithms.o  sortLarge.o -o run

sortingAlgorithms.o: sortingAlgorithms.cpp
	g++ -c sortingAlgorithms.cpp


sortLarge.o: sortLarge.cpp
	g++ -c sortLarge.cpp
clean:
	rm -rf *.o run
