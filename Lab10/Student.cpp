#include "Student.h"

Student::Student(string inName, int inID) {
	name = inName;
	ID = inID;
}

bool Student::operator==(const Student &inVal) {
	return ((this->ID == inVal.ID) && (this->name.compare(inVal.name) == 0));
}

bool Student::operator!=(const Student& inVal) {
	return (this->ID == inVal.ID);
}

Student::operator string() {
	string ret = to_string(ID);
	return ret;
}


