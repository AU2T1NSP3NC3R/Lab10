#include "Student.h"

Student::Student() {
	name = "None";
	ID = 0;
}

Student::operator string() {
	string ret = to_string(ID);
	return ret;
}


