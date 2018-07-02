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
 
#ifndef SIMPLE_LIST_ITERATOR_DECS
#define SIMPLE_LIST_ITERATOR_DECS

template <class T>
class ListIterator;

#include "ListEntry.hpp"
#include "List.hpp"

 
template <class T>
class ListIterator {
	friend class List<T>;
	private:
		ListEntry<T>* _prev;
		ListEntry<T>* _current;
		ListEntry<T>* _next;
		List<T>* _parent;
		bool _valid;
		ListIterator(List<T>* parent, ListEntry<T>* prev, ListEntry<T>* next);
	public:
		void remove();
		T next();
		T prev();
		bool has_next();
		bool has_prev();
		~ListIterator();
};

#include "ListIterator.cpp"
#endif