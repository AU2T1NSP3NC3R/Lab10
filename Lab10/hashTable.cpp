#include "hashTable.h"
template <class T>
hashTable<T>::hashTable() {
	items = 0;
	arr = new T*[MAX_SIZE];
}

template <class T>
hashTable<T>::hashTable(int inVal) {	// calls setMAX_SIZE so we can always % the hash value by the same variable
	items = 0;
	setMAX_SIZE(inVal);
	arr = new T*[MAX_SIZE];
}

template <class T>
void hashTable<T>::setMAX_SIZE(int inVal) {
	MAX_SIZE = inVal;
}


template <class T>
void hashTable<T>::addItem(T* inVal) {	// currently works but we need at collision handling
	string sku_str = string(*inVal);
	int address = hash(sku_str);
	arr[address] = inVal;
}

template <class T>
T* hashTable<T>::removeItem(T*) {

}

template <class T>
int hashTable<T>::getLength() {
	return items;
}

template <class T>
int hashTable<T>::hash(string inVal) {	// ret represents the hash value that will be returned from the string inVal
	int ret = 0;
	for (int i = 0; i < inVal.length(); i++) {
		char x = inVal.at(i);
		ret += int(x);
	}
	ret %= MAX_SIZE;
	cout << "hash value: " << ret << endl;
	return ret;
}

template <class T>
hashTable<T>::~hashTable() {

}