CFLAGS=-c -Wall
all: main
main:main.o student.o
	g++ main.o student.o -o main
main.o:main.cpp
	g++ $(CFLAGS) main.cpp
student.o:student.cpp
	g++ $(CFLAGS) student.cpp
clean:
	rm -fr *o main