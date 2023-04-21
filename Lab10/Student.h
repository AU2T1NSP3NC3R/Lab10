#pragma once
#include <string>

using namespace std;

class Student
{
	public:
		Student(string, int);

		int ID;
		string name;

		bool operator!=(const Student&);
		bool operator==(const Student&);
		operator string();
};

