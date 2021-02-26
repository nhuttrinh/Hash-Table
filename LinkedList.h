#ifndef _LinkedList_h_
#define _LinkedList_h_

#include <string>
#include <sstream>
using namespace std;


typedef struct Node {
	Node(int val) : prev(NULL), next(NULL), value(0) { value = val; }
	struct Node* prev;
	struct Node* next;
	int value;
} Node_t;

class LinkedList {
private:
	int size;
	Node_t *head, *tail;

public:
	LinkedList();

	void push_back(Node_t* n);
	void push_front(Node_t* n);

	bool findValue(int value);

	string print();

	int getSize() {
		return size;
	}
};
#endif

