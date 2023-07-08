hw4: main.o HashTable.o LinkedList.o Queue.o Stack.o Word.o WordNetwork.o
	g++ main.o HashTable.o LinkedList.o Queue.o Stack.o Word.o WordNetwork.o -o hw4

main.o: main.cpp
	g++ -c main.cpp

HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Word.o: Word.cpp Word.h
	g++ -c Word.cpp

WordNetwork.o: WordNetwork.cpp WordNetwork.h
	g++ -c WordNetwork.cpp

# Cleans the object files and executable
clean:
	rm *.o hw4