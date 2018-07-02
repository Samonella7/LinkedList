/*
 * A very lightweight implementation of a doubly linked-list, useful only for 
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
 * Since this is designed for the the simplest of CPUs, don't 
 * expect any fancy exceptions or things to help you debug. 
 * Never use more than one iterator per list at a time, and don't 
 * add elements while using an iterator.
 *
 * Author: Jason Schwarzenberger and Samuel Thayer
 */
 
#ifndef SIMPLE_LIST_DECS
#define SIMPLE_LIST_DECS

template <class T>
class List;

#include "ListEntry.hpp"
#include "ListIterator.hpp"

 
template <class T>
class List {
	friend class ListIterator<T>;
	private:
		ListEntry<T>* _head;
		ListEntry<T>* _tail;
		int _list_size;
		void remove(ListEntry<T>* entry);
	public:
		List();
		ListIterator<T> front();
		ListIterator<T> back();
		int size();
		void push_back(T new_entry);
		void push_front(T new_entry);
		void erase(ListIterator<T> position);
		~List();
};

#include "List.cpp"
#endif