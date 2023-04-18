#include "hashTable.h"
template <class T>
hashTable<T>::hashTable() {	// default constructor
	items = 0;
	arr = new T*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = nullptr;
	}
}

template <class T>
hashTable<T>::hashTable(int inVal) {	// calls setMAX_SIZE so we can always % the hash value by the same variable
	items = 0;
	setMAX_SIZE(inVal);
	arr = new T*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = nullptr;
	}
}

template <class T>
void hashTable<T>::setMAX_SIZE(int inVal) {	// used to create a custom sized table
	MAX_SIZE = inVal;
}


template <class T>
void hashTable<T>::addItem(T* inVal) {	// address represents the index of where inVal will be placed within the array
	if (items == MAX_SIZE) {	// covers adding to a full table
		try {
			throw OverflowError();
		}
		catch (OverflowError ex) {
			ex.what();
		}
		return;
	}
	
	string sku_str = string(*inVal);
	int address = hash(sku_str);

	if (arr[address] == nullptr) {// covers case where nothing is stored at the hash value
		arr[address] = inVal;
		items++;
	}
	else {	// covers collisions
		while (arr[address] != nullptr) {	// iterates address to next open spot within the array
			if (address < MAX_SIZE) {
				address++;
			}
			else if (address == MAX_SIZE) {	// resets address to front of array when it iterates to end
				address = 0;
			}
		}
		arr[address] = inVal;
		items++;
	}
	return;
}

template <class T>
T* hashTable<T>::removeItem(T* inVal) {
	if (items == 0) {	// covers removing from an empty table
		try {
			throw UnderflowError();
		}
		catch (UnderflowError ex) {
			ex.what();
		}
		return nullptr;
	}

	T* ret = nullptr;
	string sku_str = string(*inVal);
	int address = hash(sku_str);
	int spotsChecked = 0;

	
	if (arr[address] != nullptr && *arr[address] == *inVal) {	// item was placed with no collision and is found instantly
		ret = arr[address];
		arr[address] = nullptr;	// might cause ret to turn into nullptr, consider changing prev line to 'ret = inVal'
		items--;
		return ret;
	}
	else {	// Logic that covers removing items that were placed with collision
		address = 0;
		while (spotsChecked < MAX_SIZE) {	// while loop will terminate if inVal is found, or it checks every spot and does not find inVal
			if (arr[address] == nullptr) {
				address++;
				spotsChecked++;
			}
			else {	// checks all entries in table that are not nullptr
				if (*arr[address] == *inVal) {
					ret = arr[address];
					arr[address] = nullptr;
					items--;
					return ret;
				}
				else {
					address++;
					spotsChecked++;
				}
			}
		}
		return ret;
	}
}

template <class T>
T** hashTable<T>::getItem(T* inval) {

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
	return ret;
}

template <class T>
void hashTable<T>::printTable() {	// goes through and calls display member function for each item in list
	for (int i = 0; i < MAX_SIZE; i++) {
		if (arr[i] != nullptr) {
			T toPrint = *arr[i];
			toPrint.display();
			cout << endl;
		}
	}
}

template <class T>
hashTable<T>::~hashTable() {

}