#include "chainHashTable.h"
template <class T>
chainHashTable<T>::chainHashTable() {	// default constructor
	items = 0;
	comps = 0;
	arr = new node * [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = nullptr;
	}
}

template <class T>
chainHashTable<T>::chainHashTable(int inVal) {	// calls setMAX_SIZE so we can always % the hash value by the same variable
	items = 0;
	setMAX_SIZE(inVal);
	arr = new node * [MAX_SIZE];
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
		node* newNode = new node;
		newNode->data = inVal;
		newNode->next = nullptr;
		arr[address] = newNode;
		items++;
	}
	else {	// covers collisions
		node* temp = arr[address];
		while (temp->next != nullptr) {	// iterates address to next open spot within the array
			temp = temp->next;
		}
		node* newNode = new node;
		newNode->data = inVal;
		newNode->next = nullptr;
		temp->next = newNode;
		items++;
	}
	return;
}

template <class T>
T* chainHashTable<T>::removeItem(T* inVal) {
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


	if (arr[address] != nullptr && *arr[address]->data == *inVal) {	// item was placed with no collision and is found instantly
		ret = arr[address]->data;
		if (arr[address]->next == nullptr) {
			delete arr[address];
			arr[address] = nullptr;	// might cause ret to turn into nullptr, consider changing prev line to 'ret = inVal'
		}
		else {
			node* temp = arr[address];
			arr[address] = arr[address]->next;
			delete temp;
		}
		items--;
		return ret;
	}
	else if(arr[address] != nullptr && *arr[address]->data != *inVal) {	// Logic that covers removing items that were placed with collision
		node* temp = arr[address];
		while (*temp->next->data != *inVal) {
			if (temp->next->next == nullptr) {
				//not in hash table
				return nullptr;
			}
			temp = temp->next;
		}
		ret = temp->next->data;
		node* rem = temp->next;
		temp->next = temp->next->next;
		delete rem;
		items--;
		return ret;
	}
	else {
		//not in hashTable
		return nullptr;
	}
}

template <class T>
T* chainHashTable<T>::getItem(T* inVal) {
	if (items == 0) {	// covers getting from an empty table
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


	if (arr[address] != nullptr && *arr[address]->data == *inVal) {	// item was placed with no collision and is found instantly
		ret = arr[address]->data;
		comps++;
		return ret;
	}
	else if (arr[address] != nullptr && *arr[address]->data != *inVal) {// Logic that covers getting items that were placed with collision
		comps++;
		node* temp = arr[address];
		while (*temp->next->data != *inVal) {	// will iterate until temp is at spot before inval
			comps++;
			if (temp->next->next == nullptr) {
				//not in hash table
				return nullptr;
			}
			temp = temp->next;
		}
		comps++;
		ret = temp->next->data;	// moves temp to equal inval and stores value in ret
		return ret;
	}
	else {
		//not in hashTable
		return nullptr;
	}
}

template <class T>
int chainHashTable<T>::getLength() {
	return items;
}

template <class T>
void chainHashTable<T>::printTable() {	// goes through and calls display member function for each item in list
	for (int i = 0; i < MAX_SIZE; i++) {
		if (arr[i] != nullptr) {
			node* temp = arr[i];
			while (temp != nullptr) {
				T toPrint = *arr[i]->data;
				toPrint.display();
				cout << endl;
				temp = temp->next;
			}
		}
	}
}

template <class T>
chainHashTable<T>::~chainHashTable() {
	delete[] arr;
}