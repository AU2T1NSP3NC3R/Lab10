#include "hashTable.h"
template <class T>
hashTable<T>::hashTable() {
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
void hashTable<T>::setMAX_SIZE(int inVal) {
	MAX_SIZE = inVal;
}


template <class T>
void hashTable<T>::addItem(T* inVal) {	// address represents the index of where inVal will be placed within the array
	if (items == MAX_SIZE) {
		// throw overflow error
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
	if (items == 0) {
		// throw underflow exception
	}

	T* ret = nullptr;
	string sku_str = string(*inVal);
	int address = hash(sku_str);
	int spotsChecked = 0;

	
	if (*arr[address] == *inVal) {	// item was placed with no collision and is found instantly
		ret = arr[address];
		arr[address] = nullptr;	// might cause ret to turn into nullptr, consider changing prev line to 'ret = inVal'
		return ret;
	}
	else {	// ADD LOGIC THAT COVERS COLLISIONS HERE
		while (*arr[address] != *inVal && spotsChecked < MAX_SIZE) {// iterates until arr[address] == inVal or each spot is checked
			if (address < MAX_SIZE) {
				address++;
				spotsChecked++;
			}
			else if (address == MAX_SIZE) {	// resets address to front of array after it iterates till end
				address = 0;
				spotsChecked++;
			}
		}
		if (*arr[address] == *inVal) {
			ret = arr[address];
			arr[address] = nullptr;
			return ret;
		}
	}
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
void hashTable<T>::printTable() {
	for (int i = 0; i < items; i++) {
		cout << "item(" << i << "): " << arr[i] << endl;
	}
}

template <class T>
hashTable<T>::~hashTable() {

}