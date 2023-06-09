#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
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
	T* getItem(T*);
	int getLength();
	void printTable();

	int comps;
private:
	T** arr;
	int hash(string);
	int items;
	int MAX_SIZE = 100;
};

