Hashtable: main.o hashTable.o LinkedList.o

	g++ -o Hashtable main.o  hashTable.o LinkedList.o

main.o : main.cpp
	g++ -c main.cpp 
hashTable.o: hashTable.cpp
	g++ -c hashTable.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
