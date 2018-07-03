/*
 * A very lightweight implementation of a doubly-linked list, useful only for 
 * projects like arduino programming, where including the standard library is impractical.
 *
 * Compared to the standard library list, this List seems incredibly simple and featureless. 
 * Proper usage only includes:
 *  - Adding to the front and back of the list:
 *  	push_back()
 *		push_front()
 *  - Getting the number of elements in the list:
 *		size()
 *  - Getting iterators
 * 		front()
 *		back()
 * See ListIterator.cpp for details on the iterators
 *
 * Author: Jason Schwarzenberger and Samuel Thayer
 */
 
 #ifndef SIMPLE_LIST_DEFS
 #define SIMPLE_LIST_DEFS

#include "List.hpp"
#include "ListEntry.hpp"
#include "ListIterator.hpp"


template <class T>
List<T>::List() {
	_head = nullptr;
	_tail = nullptr;
	_list_size = 0;
}

template <class T>
ListIterator<T> List<T>::front() {
	return ListIterator<T>(this, nullptr, _head);
}

template <class T>
ListIterator<T> List<T>::back() {
	return ListIterator<T>(this, _tail, nullptr);
}

template <class T>
int List<T>::size() {
	return _list_size;
}

template <class T>
void List<T>::push_back(T new_entry) {
	ListEntry<T>* new_node = new ListEntry<T>(new_entry);
	
	if (_head == nullptr) {
		_head = new_node;
		_tail = new_node;
		_list_size = 1;
	} else {
		_tail->_next = new_node;
		new_node->_prev = _tail;
		_tail = new_node;
		_list_size++;
	}
}

template <class T>
void List<T>::push_front(T new_entry) {
	ListEntry<T>* new_node = new ListEntry<T>(new_entry);
	
	if (_head == nullptr) {
		_head = new_node;
		_tail = new_node;
		_list_size = 1;
	} else {
		_head->_prev = new_node;
		new_node->_next = _head;
		_head = new_node;
		_list_size++;
	}
}

template <class T>
void List<T>::erase(ListIterator<T> position) {
	position.remove();
}

template <class T>
void List<T>::remove(ListEntry<T>* entry) {
	
	ListEntry<T>* prev = entry->_prev;
	ListEntry<T>* next = entry->_next;
	
	if (prev != nullptr) {
		prev->_next = next;
	} else {
		_head = next;
	}
	
	if (next != nullptr) {
		next->_prev = prev;
	} else {
		_tail = prev;
	}
	
	_list_size--;
	delete entry;
}

template <class T>
List<T>::~List() {
	while (_head) {
		ListEntry<T>* next = _head->_next;
		delete _head;
		_list_size = _list_size - 1;
		_head = next;
	}
}


#endif