#include "hashTable.h"
template <class T>
hashTable<T>::hashTable() {
	items = 0;
	arr = new Node*[MAX_SIZE];
}

template <class T>
hashTable<T>::~hashTable() {

}