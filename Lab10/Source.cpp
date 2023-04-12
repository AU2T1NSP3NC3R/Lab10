#include <iostream>
#include "hashTable.h"
#include "hashTable.cpp"
#include "Part.h"


int main() {
	hashTable<Part> myTable;

	Part z = Part(12355, "desk", 150, "meters", 10);
	Part* ptr = &z;

	Part x = Part(12355, "pencil", 1, "inches", 1453);
	Part* ptr2 = &x;

	myTable.addItem(ptr);

	return 0;
}