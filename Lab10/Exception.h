#pragma once
#include <exception>
#include <iostream>

using namespace std;

class OverflowError : public std::exception
{
public:
	char const* what() {
		cout << "Overflow Error" << endl;
		return "\n Overflow Error";
	}
};

class UnderflowError : public std::exception
{
public:
	char const* what() {
		cout << "Underflow Error" << endl;
		return "\n Underflow Error";
	}
};