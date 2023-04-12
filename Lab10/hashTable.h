#pragma once
#include <string>
#include <iostream>
using namespace std;

template <class T>
class hashTable
{
public:
	hashTable();
	hashTable(int);
	~hashTable();
	void addItem(T*);
	void setMAX_SIZE(int);
	T* removeItem(T*);
	int getLength();
private:
	T** arr;
	int hash(string);
	int items;
	int MAX_SIZE = 100;
};

