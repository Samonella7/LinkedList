/*
 * An iterator for a lightweight doubly-linked list. 
 * Modeled after Java iterators instead of c++ ones, because, frankly,
 * it was easier.
 *
 * Proper usage only includes:
 *  - Checking whether there is a next/previous element
 *		has_next()
 *		has_prev()
 *  - Getting the next-previous element
 *  	next()
 *		prev()
 *  - Removing the current element from the list this iterator came from
 *	  ("current" means the one that was most recently returned by next() or prev())
 *		remove()
 *
 * Since this is designed for the the simplest of CPUs, don't 
 * expect any fancy exceptions or things to help you debug. 
 * Just never call next() without checking has_next() and you'll do fine.
 *
 * Author: Samuel Thayer
 */
 
 #ifndef SIMPLE_LIST_ITERATOR_DEFS
 #define SIMPLE_LIST_ITERATOR_DEFS

#include "ListIterator.hpp"
#include "ListEntry.hpp"
#include "List.hpp"

template <class T>
ListIterator<T>::ListIterator(List<T>* parent, ListEntry<T>* prev, ListEntry<T>* next) {
	_prev = prev;
	_current = nullptr;
	_next = next;
	_parent = parent;
	_valid = false;
}

template <class T>
void ListIterator<T>::remove() {
	if (!_valid)
		return;
	
	_valid = false;
	_parent->remove(_current);
}

template <class T>
bool ListIterator<T>::has_next() {
	return !(_next == nullptr);
}

template <class T>
bool ListIterator<T>::has_prev() {
	return !(_prev == nullptr);
}

template <class T>
T ListIterator<T>::next() {
	if (_next == nullptr) {
		throw 1;
	} else {
		_valid = true;
		_current = _next;
		_prev = _current->_prev;
		_next = _current->_next;
		return _current->data();
	}
}

template <class T>
T ListIterator<T>::prev() {
	if (_prev == nullptr) {
		throw 1;
	} else {
		_valid = true;
		_current = _prev;
		_prev = _current->_prev;
		_next = _current->_next;
		return _current->data();
	}
}

template <class T>
ListIterator<T>::~ListIterator() { }


#endif