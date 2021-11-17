all: run

run: hash.o
	g++ -std=c++11 hash.o -o run

hash.o: hash.cpp
	g++ -std=c++11 -c hash.cpp

clean:
	rm -rf *.o run 
