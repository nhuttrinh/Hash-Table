#ifndef _hashTable_h_
#define _hashTable_h_

#include <string>
#include <sstream>
#include <math.h>

#include "LinkedList.h"

using namespace std;

class hashTable {
private:
	int p; // number of slots
	double alpha; // alpha for linear hash key
	LinkedList** slots;

public:
	hashTable(int, double);

	string print();

	void chainedHashInsert(int);
	int chainedHashSearch(int);

	void hashInsertLinear(int);
	string hashSearchLinear(int);

	void hashInsertDouble(int);
	string hashSearchDouble(int);

	// Returns the number of slots
	int getSize() {
		return p;
	}
};

#endif

