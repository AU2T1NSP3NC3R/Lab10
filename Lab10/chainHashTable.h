#pragma once
#include <string>
template <class T>
class chainHashTable{
public:
	struct node {
		T* data;
		node* next;
	};
	chainHashTable();
	chainHashTable(int);
	~chainHashTable();
	void addItem(T*);
	void setMAX_SIZE(int);
	T* removeItem(T*);
	T* getItem(T*);
	int getLength();
	void printTable();
private:
	T** arr;
	int hash(string);
	int items;
	int MAX_SIZE = 100;
};

