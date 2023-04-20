#pragma once
#include <string>

using namespace std;

class Student
{
	public:
		Student();

		int ID;
		string name;

		operator string();
};

