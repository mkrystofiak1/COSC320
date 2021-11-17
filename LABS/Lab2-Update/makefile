all: run

run: sortingAlgorithms.o  quick.o 
	g++ -std=c++11 sortingAlgorithms.o quick.o -o run

sortingAlgorithms.o: sortingAlgorithms.cpp
	g++ -std=c++11 -c sortingAlgorithms.cpp

quick.o: quick.cpp
	g++ -std=c++11 -c quick.cpp

clean:
	rm -rf *.o run
