clean :
	rm *.o *.out

all : Node.o LinkedList.o main.cpp
	g++ Node.o LinkedList.o main.cpp

Node.o : Node.cpp Node.h
	g++ -c Node.cpp -o Node.o

LinkedList.o : LinkedList.cpp LinkedList.h Node.o
	g++ -c LinkedList.cpp -o LinkedList.o