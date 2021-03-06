/*
 * Represents a node of the List class. Should only be used internally 
 * by List and ListIterator; outside code should never need to declare a ListEntry.
 *
 * Features are as lightweight as the List it is made for.
 *
 * Author: Jason Schwarzenberger and Samuel Thayer
 */

#ifndef SIMPLE_LIST_ENTRY_DECS
#define SIMPLE_LIST_ENTRY_DECS


template <class T>
class ListEntry {
	private:
		T _data;
	public:
		ListEntry* _next;
		ListEntry* _prev;
		ListEntry(T data);
		T data();
		~ListEntry();
};

#include "ListEntry.cpp"
#endif