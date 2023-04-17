#include <iostream>
#include "hashTable.h"
#include "hashTable.cpp"
#include "Part.h"


int main() {
	hashTable<Part> myTable = hashTable<Part>(3);

	Part x = Part(55, "5", 5, "5", 14);
	Part* y = &x;

	Part v = Part(55, "4", 4, "4", 19);
	Part* z = &v;

	Part t = Part(55, "3", 3, "3", 3);
	Part* d = &t;

	myTable.addItem(y);
	myTable.addItem(z);
	myTable.addItem(d);

	myTable.printTable();

	Part* toRemove = myTable.removeItem(z);
	bool tableMade = false;
	char con = 'y';
	char dec = 'z';
	/*
	while (con == 'y' || con == 'Y') {
		while (!tableMade) {
			cout << "-----------------------------" << endl;
			cout << "| (1): Create a default size hash table" << endl;
			cout << "| (2): Create a custom sized hash table" << endl;
			cout << "-----------------------------" << endl;
			cout << "| Pick one of the preceeding choices: ";
			cin >> dec;
			cout << endl;

			if (dec == '1') {
				hashTable<Part> myTable = hashTable<Part>();
				tableMade = true;
			}
			else if (dec == '2') {
				int tableSize = 0;

				cout << "-----------------------------" << endl;
				cout << "| Enter the desired size of the hash table: ";
				cin >> tableSize;
				cout << endl;
				hashTable<Part> myTable = hashTable<Part>(tableSize);
				tableMade = true;
			}
			else {
				cout << "YOU ENTERED AN INCORRECT VALUE // PLEASE TRY AGAIN" << endl;
				cout << endl;
			}
		}
		cout << "-----------------------------" << endl;
		cout << "| (1): Add an item" << endl;
		cout << "| (2): Remove an item" << endl;
		cout << "| (3): Get the length" << endl;
		cout << "| (4): View the table" << endl;
		cout << "-----------------------------" << endl;
		cout << "| Pick one of the preceeding choices: ";
		cin >> dec;
		cout << endl;

		if (dec == '1') {
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
			cout << endl;

			Part* toAdd = new Part(s, d, p, u, q);
			Part toDisplay = Part(s, d, p, u, q);
			myTable.addItem(toAdd);


			cout << "| You added the following item to the list: " << endl;
			toDisplay.display();
		}
		else if (dec == '2') {

		}
		else if (dec == '3') {

		}
		else if (dec == '4') {

		}
		else {
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