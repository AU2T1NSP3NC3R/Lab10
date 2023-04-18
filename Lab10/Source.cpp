#include <iostream>
#include "hashTable.h"
#include "hashTable.cpp"
#include "Part.h"


int main() {

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
		else if (dec == '2') {
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
		else if (dec == '3') {
			cout << "-----------------------------" << endl;
			cout << "| Length: " << myTable.getLength() << endl;
			cout << "-----------------------------" << endl;
		}
		else if (dec == '4') {
			cout << "-----------------------------" << endl;
			cout << endl;
			myTable.printTable();
			cout << "-----------------------------" << endl;
		}
		else {
			cout << "YOU ENTERED AN INCORRECT VALUE // PLEASE TRY AGAIN" << endl;
		}

		cout << "-----------------------------" << endl;
		cout << "| Would you like to continue (y/n): ";
		cin >> con;
		cout << endl;
	}
	
	return 0;
}