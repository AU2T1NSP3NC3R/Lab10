#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
class Part
{
	private:
		int sku;
		string desc;
		double price;
		string uom; // unit of measurement
		int qoh; // quantity on hand
		double lt; // leadtime
	public:
		Part();
		Part(int sku, string desc, double price, string uom, int qoh);
		Part(int sku, string desc, double price, string uom);
		void setSku(int);
		string getPartInfo();
		double getPrice();
		bool inStock();
		bool available(tm);

		void display();

		bool operator<(const Part&);
		bool operator>(const Part&);
		bool operator<=(const Part&);
		bool operator>=(const Part&);
		bool operator!=(const Part&);
		bool operator==(const Part&);
		operator string();
};

