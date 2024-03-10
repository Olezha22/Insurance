#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Insurance abstract
{
protected:
	double insurance_price;
public:
	Insurance() = default;
	Insurance(double price);
	Insurance(const Insurance& I) = default;
	virtual ~Insurance();

	virtual void printOn(std::ostream& os) const abstract;
	virtual void readFrom(std::istream& is) abstract;
	virtual double totalPrice() const abstract;
	virtual void print() abstract;

	bool operator<(const Insurance& I) const;
	bool operator>(const Insurance& I) const;


	friend std::ostream& operator<<(std::ostream& os, const Insurance& I);
	friend std::istream& operator>>(std::istream& is, Insurance& I);
};



Insurance** createArr(std::string file, size_t& n);
void printArr(Insurance** ins, size_t n);
double calculateTotalValue(Insurance** ins, size_t n);
Insurance* findMostExpensive(Insurance** ins, size_t n);
Insurance* findMostCheap(Insurance** ins, size_t n);



