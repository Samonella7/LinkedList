/*
 * Represents a node of the List class. Should only be used internally 
 * by List and ListIterator; outside code should never need to declare a ListEntry.
 *
 * Features are as lightweight as the List it is made for.
 *
 * Author: Jason Schwarzenberger and Samuel Thayer
 */
 
#ifndef SIMPLE_LIST_ENTRY_DEFS
#define SIMPLE_LIST_ENTRY_DEFS

#include "ListEntry.hpp"

template <class T>
ListEntry<T>::ListEntry(T data) {
	_data = data;
	_next = nullptr;
	_prev = nullptr;
}

template <class T>
T ListEntry<T>::data() {
	return _data;
}

template <class T>
ListEntry<T>::~ListEntry() { }

#endif