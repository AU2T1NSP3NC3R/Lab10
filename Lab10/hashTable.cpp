#include "hashTable.h"
template <class T>
hashTable<T>::hashTable() {
	items = 0;
	arr = new Node*[MAX_SIZE];
}

template <class T>
hashTable<T>::~hashTable() {

}

template <class T>
void hashTable<T>::addItem(T*) {

}

template <class T>
T* hashTable<T>::removeItem(T*) {

}

template <class T>
int hashTable<T>::getLength() {
	return items;
}

template <class T>
int hashTable<T>::hash(T*) {

}