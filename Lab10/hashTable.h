#pragma once
#include <string>
using namespace std;

template <class T>
class hashTable
{
public:
	hashTable();
	~hashTable();
	void addItem(T*);
	T* removeItem(T*);
	int getLength();
private:
	struct Node {
		int key = 0;
		T* obj = nullptr;
	};
	Node** arr;
	int hash(T*);
	int items;
	int MAX_SIZE = 100;
};

