#include "hashTable.h"

/* HashTable Constructor */
hashTable::hashTable(int s, double a) {
	 alpha = a;
	 p = s;

	slots = new LinkedList *[p];

	// Initialize all slots in the vector as linked lists
	for(int i = 0; i < p; i++) {
		slots[i] = new LinkedList();
	}
}


/* Print each slot and its contains*/
string hashTable::print() {
	stringstream ss;
	for(int i = 0; i < p; i++) {
		ss << i << ": " << slots[i]->print() << "\n";
	}
	return ss.str();
}


/* Chained Hash Insert */
void hashTable::chainedHashInsert(int k) {
	// Calculate the slot for k.
	int h = k%p;

	// Push k to the front of the linked list.
	slots[h]->push_front(new Node_t(k));
}

/*Chained Hash Search */
int hashTable::chainedHashSearch(int k) {
	// Calculate the slot for k.
	int h = k%p;

	// Check to see if k is in the linked list at the index of Hash Table.
	if(slots[h]->findValue(k))
		return h;

	return -1;
}


/* Hash Insert Linear (Open addressing)
 * h_prime = floor(p*((alpha*k) mod 1))
 * h = (h_prime + i) mod p
 */
void hashTable::hashInsertLinear(int k) {
	// Keep calculate until find an empty slot for k.
	int h = 0;
	double x = alpha*k;
        double b = x - ((int)(x/1));
        int h_prime = floor(b*p);
	for(int i = 0; i < p; i++) {
		h = (h_prime + i)%p;
		if(slots[h]->getSize() == 0) {
			slots[h]->push_back(new Node_t(k));
			return;
		}
	}
}


/* Hash Search Linear*/
string hashTable::hashSearchLinear(int k) {
	stringstream ss;
	// Probe to find a slot for k.
	int h = 0;
	double x = alpha*k;
	double b = x - ((int)(x/1));
	int h_prime = floor(b*p);
	for(int i = 0; i < p; i++) {
		h = (h_prime + i)%p;
		ss << h << " ";
		if(slots[h]->findValue(k))
			break;
	}
	return ss.str();
}


/*
 * Hash Insert Double
 * Inserts a k into a linked list at the appropriate hash table slot.
 *	h1 = k mod p
 *	h2 = 1 + (k mod (p-2))
 *	h = h1 + i*h2
 */
void hashTable::hashInsertDouble(int k) {
	// Probe to find slot for k
	int h = 0;
	for(int i = 0; i < p; i++) {
		h = ((k%p) + i*(1+(k%(p-2))))%p;
		// Slot is empty then insert k
		if(slots[h]->getSize() == 0) {
			slots[h]->push_back(new Node_t(k));
			return;
		}
	}
}

/*Hash Search Double */
string hashTable::hashSearchDouble(int k) {
	stringstream ss;
	// Probe to find empty slot for k.
	int h = 0;
	for(int i = 0; i < p; i++) {
		h = ((k%p) + i*(1+(k%(p-2))))%p;
		ss << h << " ";
		if(slots[h]->findValue(k))
			break;
	}
	return ss.str();
}

