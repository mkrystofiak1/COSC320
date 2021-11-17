all: clean iomodel driver

iomodel: iomodel.o Matrix.o
	g++ -std=c++11 iomodel.o Matrix.o -o iomodel

iomodel.o: iomodel.cpp Matrix.cpp
	g++ -std=c++11 -c iomodel.cpp Matrix.cpp

driver: driver.o Matrix.o
	g++ -std=c++11 driver.o Matrix.o -o driver

driver.o: driver.cpp Matrix.cpp
	g++ -std=c++11 -c driver.cpp Matrix.cpp

Matrix.o: Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm -rf *.o iomodel driver
