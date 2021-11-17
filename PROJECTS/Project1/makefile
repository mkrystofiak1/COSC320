all: run

run: driver.o Matrix.o
	g++ -std=c++11 driver.o Matrix.o -o run

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

Matrix.o: Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm -rf *.o run
