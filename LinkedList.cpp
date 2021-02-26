#include "LinkedList.h"

/* LinkedList constructor. */
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

/* Add a node to the end of the Linked List*/
void LinkedList::push_back(Node_t* n) {
	// List is empty
	if(head == NULL) {
		head = n;
		tail = n;
	} else {
		tail->next = n;
		n->prev = tail;
		n->next = NULL;
		tail = n;
	}
	size++;
}

/* Add a node to the front of a Linked List. */
void LinkedList::push_front(Node_t* n) {
	// List is empty
	if(head == NULL) {
		head = n;
		tail = n;
	} else {

		head->prev = n;
		n->next = head;
		head = n;
	}
	size++;
}


/* Find value if it is in the Linked List. */
bool LinkedList::findValue(int val) {
	Node_t* next = head;
	while(next != NULL) {
		if(next->value == val)
			return true;
		next = next->next;
	}
	return false;
}

/* Print Linked List. */
string LinkedList::print() {
	stringstream ss;
	Node_t* next = head;
	while(next != NULL) {
		ss << next->value << " ";
		next = next->next;
	}
	return ss.str();
}

