#pragma once
#include <exception>
#include <iostream>

using namespace std;

class EmptyListError : public std::exception
{
public:
	char const* what() {
		cout << "Empty List Error" << endl;
		return "\n Empty List Error";
	}
};