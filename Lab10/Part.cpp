#include "Part.h"

Part::Part() {
	sku = 0;
	desc = "";
	price = 0;
	uom = "";
	qoh = 0;
}

Part::Part(int sku_, string desc_, double price_, string uom_, int qoh_) {
	sku = sku_;
	desc = desc_;
	price = price_;
	uom = uom_;
	qoh = qoh_;
}

Part::Part(int sku_, string desc_, double price_, string uom_) {
	sku = sku_;
	desc = desc_;
	price = price_;
	uom = uom_;
}

void Part::setSku(int inVal) {
	sku = inVal;
}

string Part::getPartInfo() {
	return(to_string(sku) + ": " + desc);
}

double Part::getPrice() {
	return price;
}

bool Part::inStock() {
	return(qoh > 0);
}

bool Part::available(tm desiredDay) {	// In order for script to compile we had to disable deprecation using '_CRT_SECURE_NO_WARNINGS'
	time_t now = time(0);
	tm* curr = localtime(&now);
	if (qoh > 0) {
		return true;
	}
	else if ((curr->tm_mday + lt) < desiredDay.tm_mday) {
		if (curr->tm_mon == desiredDay.tm_mon) {
			if (curr->tm_year == desiredDay.tm_year) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

void Part::display() {
	string s_price = to_string(price);
	string s_sku = to_string(sku);
	string s_qoh = to_string(qoh);
	string s_desc = desc;
	cout << " ------------------------" << endl;
	cout << "|                        |" << endl;
	cout << "| " << s_desc;
	for (int i = 0; i < 22 - desc.size(); i++) {
		cout << " ";
	}
	cout << " |" << endl;
	cout << "|                        |" << endl;
	cout << fixed << setprecision(2) << "| $" << price;
	for (int i = 0; i < 25 - s_price.length(); i++) {
		cout << " ";
	}
	cout << " |" << endl;
	cout << "|                        |" << endl;
	cout << "| SKU: " << sku;
	for (int i = 0; i < 17 - s_sku.length(); i++) {
		cout << " ";
	}
	cout << " |" << endl;
	cout << "|                        |" << endl;
	cout << "| QOH: " << s_qoh;
	for (int i = 0; i < 17 - s_qoh.length(); i++) {
		cout << " ";
	}
	cout << " |" << endl;
	cout << "|                        |" << endl;
	cout << " ------------------------" << endl;
}

bool Part::operator<(const Part& inVal) {
	return(this->sku < inVal.sku);
}

bool Part::operator>(const Part& inVal) {
	return(this->sku > inVal.sku);
}

bool Part::operator<=(const Part& inVal) {
	return(this->sku <= inVal.sku);
}

bool Part::operator>=(const Part& inVal) {
	return(this->sku >= inVal.sku);
}

bool Part::operator!=(const Part& inVal) {
	return(this->sku != inVal.sku);
}

bool Part::operator==(const Part& inVal) {
	return(this->sku == inVal.sku);
}
