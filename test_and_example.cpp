#include "List.hpp"

#include <iostream>
using namespace std;

typedef string type;

static bool success;

template <class T>
void check (T expected, T actual) {
	if (expected != actual) {
		cout << "Error: expected '" << expected << "' but was '" << actual << "'" << endl;
		success = false;
	}
}


string printList (List<type>* myList) {
	string retVal = "";
	ListIterator<type> it = myList->front();
	while (it.has_next()) {
		retVal += it.next();
	}
	return retVal;
}

string printListBackwards (List<type>* myList) {
	string retVal = "";
	ListIterator<type> it = myList->back();
	while (it.has_prev()) {
		retVal += it.prev();
	}
	return retVal;
}

void removeFromList (List<type>* myList, type removeMe) {
	ListIterator<type> it = myList->front();
	while (it.has_next()) {
		type current = it.next();
		if (current == removeMe)
			it.remove();
	}
}

void eraseFromList (List<type>* myList, type eraseMe) {
	ListIterator<type> it = myList->back();
	while (it.has_prev()) {
		type current = it.prev();
		if (current == eraseMe)
			myList->erase(it);
	}
}

int main (int argc, char** argv) {
	success = true;
	List<type>* myList = new List<type>();
	
	check(0, myList->size());
	myList->push_back("2");
	myList->push_back("3");
	check(2, myList->size());
	myList->push_back("4");
	myList->push_front("1");
	myList->push_back("5");
	check(5, myList->size());
	
	check((string)"12345", printList(myList));
	check((string)"54321", printListBackwards(myList));
	
	removeFromList(myList, "3");
	check((string)"1245", printList(myList));
	check(4, myList->size());
	
	eraseFromList(myList, "2");
	check((string)"145", printList(myList));
	check(3, myList->size());
	
	
	removeFromList(myList, "1");
	check((string)"45", printList(myList));
	check(2, myList->size());
	
	eraseFromList(myList, "5");
	check((string)"4", printList(myList));
	check(1, myList->size());
	
	eraseFromList(myList, "4");
	check((string)"", printList(myList));
	check(0, myList->size());
	
	
	
	if (success)
		cout << "No errors" << endl;
}