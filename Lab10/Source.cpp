#include <iostream>
#include <cstdlib>
#include "hashTable.h"
#include "chainHashTable.h"
#include "chainHashTable.cpp"
#include "hashTable.cpp"
#include "Part.h"
#include "Student.h"


int main() {
	Student* students[50];

	string names[2] = { "Ichibod", "Ethel" };

	for (int i = 0; i < 50; i++) {	// populates student array
		int rand_name = rand() * 2;
		int rand_ID = rand() * 500;
		students[i]->name = names[rand_name];
		students[i]->ID = rand_ID;
	}

	hashTable<Student> linear_def = hashTable<Student>();
	chainHashTable<Student> chain_def = chainHashTable<Student>();

	hashTable<Student> linear_sec = hashTable<Student>(150);
	chainHashTable<Student> chain_sec = chainHashTable<Student>(150);

	hashTable<Student> linear_thr = hashTable<Student>(200);
	chainHashTable<Student> chain_thr = chainHashTable<Student>(200);

	hashTable<Student> linear_for = hashTable<Student>(250);
	chainHashTable<Student> chain_for = chainHashTable<Student>(250);

	for (int i = 0; i < 50; i++) {	// adding to all versions of hash tables
		linear_def.addItem(students[i]);
		chain_def.addItem(students[i]);
		linear_sec.addItem(students[i]);
		chain_sec.addItem(students[i]);
		linear_thr.addItem(students[i]);
		chain_thr.addItem(students[i]);
		linear_for.addItem(students[i]);
		chain_for.addItem(students[i]);
	}



	// MAIN from Task 3 Below

	/*
	char con = 'y';
	char dec = 'z';
	int tableSize = 0;

	cout << "-----------------------------" << endl;
	cout << "| Enter the desired size of the hash table: ";
	cin >> tableSize;
	cout << endl;
	hashTable<Part> myTable = hashTable<Part>(tableSize);
	
	while (con == 'y' || con == 'Y') {

		cout << "-----------------------------" << endl;
		cout << "| (1): Add an item" << endl;
		cout << "| (2): Remove an item" << endl;
		cout << "| (3): Get the length" << endl;
		cout << "| (4): View the items in the table" << endl;
		cout << "-----------------------------" << endl;
		cout << "| Pick one of the preceeding choices: ";
		cin >> dec;
		cout << endl;

		if (dec == '1') {	// calls addItem function after prompting user to create a Part object
			int s = 0;
			string d = "";
			double p = 0;
			string u = "";
			int q = 0;
			cout << "-----------------------------" << endl;
			cout << "| Enter the item's sku: ";
			cin >> s;
			cout << endl;

			cout << "| Enter the item's description: ";
			cin.ignore();
			getline(cin, d);
			cout << endl;

			cout << "| Enter the item's price: ";
			cin >> p;
			cout << endl;

			cout << "| Enter the item's unit of measurement: ";
			cin.ignore();
			getline(cin, u);
			cout << endl;

			cout << "| Enter the item's quantity on hand: ";
			cin >> q;
			cout << "-----------------------------" << endl;
			
			Part* toAdd = new Part(s, d, p, u, q);
			Part toDisplay = Part(s, d, p, u, q);
			if (myTable.getLength() < tableSize) {
				cout << "| You added the following item to the list: " << endl;
				toDisplay.display();
				cout << "-----------------------------" << endl;
			}
			myTable.addItem(toAdd);
		}
		else if (dec == '2') {	// uses removeItem function
			int SKU = 0;
			string DESC = "";

			cout << "-----------------------------" << endl;
			cout << "| Enter the sku of the item to remove: ";
			cin >> SKU;
			cout << endl;

			cout << "| Enter the description of the item to remove: ";
			cin.ignore();
			getline(cin, DESC);
			cout << endl;

			Part* searchFor = new Part(SKU, DESC, 0, "0", 0);
			Part* ret = myTable.removeItem(searchFor);

			cout << "-----------------------------" << endl;
			cout << "| You have removed the item below: " << endl;
			if (ret != nullptr) {
				ret->display();
			}
			else {
				cout << "| Nothing in the table matched the item you wished to remove " << endl;
			}
			cout << "-----------------------------" << endl;
		}
		else if (dec == '3') {	// calls getLength function
			cout << "-----------------------------" << endl;
			cout << "| Length: " << myTable.getLength() << endl;
			cout << "-----------------------------" << endl;
		}
		else if (dec == '4') {	// calls printTable function
			cout << "-----------------------------" << endl;
			cout << endl;
			myTable.printTable();
			cout << "-----------------------------" << endl;
		}
		else {	// covers incorrect input value
			cout << "YOU ENTERED AN INCORRECT VALUE // PLEASE TRY AGAIN" << endl;
		}

		cout << "-----------------------------" << endl;
		cout << "| Would you like to continue (y/n): ";
		cin >> con;
		cout << endl;
	}
	*/
	return 0;
}