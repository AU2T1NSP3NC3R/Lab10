#include "chainHashTable.h"
template <class T>
chainHashTable<T>::chainHashTable() {	// default constructor
	items = 0;
	arr = new T * [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = nullptr;
	}
}

template <class T>
chainHashTable<T>::chainHashTable(int inVal) {	// calls setMAX_SIZE so we can always % the hash value by the same variable
	items = 0;
	setMAX_SIZE(inVal);
	arr = new T * [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = nullptr;
	}
}

template <class T>
void chainHashTable<T>::setMAX_SIZE(int inVal) {	// used to create a custom sized table
	MAX_SIZE = inVal;
}

template <class T>
int chainHashTable<T>::hash(string inVal) {	// ret represents the hash value that will be returned from the string inVal
	int ret = 0;
	for (int i = 0; i < inVal.length(); i++) {
		char x = inVal.at(i);
		ret += int(x);
	}
	ret %= MAX_SIZE;
	return ret;
}

template <class T>
void chainHashTable<T>::addItem(T* inVal) {	// address represents the index of where inVal will be placed within the array
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