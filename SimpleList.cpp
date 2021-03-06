// SimpleList.cpp

#include <iostream>
#include <string>
#include <type_traits>
#include "SimpleList.h"

// Deletes element from list
template<class T>
void destroy(T element) {
  
}

// Deletes element from list
template <class T>
void destroy(T* element) {
	// delete the pointer type
	delete element;
}

// Default constructor
template<class T>
SimpleList<T>::SimpleList() {

  this->numElements = 0;
  elements = new T[CAPACITY];

}

// Destructor
template<class T>
SimpleList<T>::~SimpleList() {

  if (std::is_pointer<T>::value) {
    for (int i = 0; i < numElements; i++) {
      destroy(elements[i]);
    }
  }
    delete[] elements;
  
}

// Returns element from array index or throws exception
template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException) {

  if (index < 0 || index >= numElements)
    throw InvalidIndexException();
  else
    return elements[index];

}

// Returns true if list is empty
template<class T>
bool SimpleList<T>::empty() const {

  if (numElements == 0)
    return true;
  else
    return false;

}

// Returns first element or throws exception
template <class T>
T SimpleList<T>::first() const throw (EmptyListException) {

  if (numElements == 0)
    throw EmptyListException();
  return elements[0];
  
}

// Returns last element or throws exception
template <class T>
T SimpleList<T>::last() const throw (EmptyListException) {

  if (numElements == 0)
    throw EmptyListException();
  else
    return elements[numElements-1];

}

// Returns number of elements
template<class T>
int SimpleList<T>::getNumElements() const {

  return numElements;
  
}

// Adds item to list or throws exception
template<class T>
void SimpleList<T>::insert(T item) throw (FullListException) {

  if (numElements == CAPACITY)
    throw FullListException();
  else {
    elements[numElements] = item;
    numElements++;
  }			     
}

// Removes item from list or throws exception
template<class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException,
					     EmptyListException) {

  if (numElements == 0)
    throw EmptyListException();
  else if (index < 0 || index >= numElements) {
    throw InvalidIndexException();
  }
  else {
    if (std::is_pointer<T>::value)
      destroy(elements[index]);
    else 
      destroy(elements[index]);
    for (int i = index+1; i < numElements; i++) {
      int j = i-1;
      elements[j] = elements[i];
    }
  }
  numElements--;
}




