all: run

run: Dictionary.o LinkedList.o timer.o main.o
	g++ -std=c++11 Dictionary.o LinkedList.o timer.o main.o -o run

Dictionary.o: Dictionary.cpp
	g++ -std=c++11 -c Dictionary.cpp

LinkedList.o: LinkedList.cpp
	g++ -std=c++11 -c LinkedList.cpp

timer.o: timer.cpp
	g++ -std=c++11 -c timer.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -rf *.o run
