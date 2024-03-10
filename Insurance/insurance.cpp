#include <iostream>
#include "insurance.h"
#include <string>
#include <fstream>
#include "carInsurance.h"
#include "familyInsurance.h"

using namespace std;

Insurance::Insurance(double price)
	: insurance_price(price)
{

}

Insurance::~Insurance()
{

}

bool Insurance::operator<(const Insurance& I) const
{
	return this->totalPrice() < I.totalPrice();
}
bool Insurance::operator>(const Insurance& I) const
{
	return this->totalPrice() > I.totalPrice();
}

std::ostream& operator<<(std::ostream& on, const Insurance& I)
{
	I.printOn(on);
	return on;
}
std::istream& operator>>(std::istream& is, Insurance& I)
{
	I.readFrom(is);
	return is;
}


Insurance** createArr(string file, size_t& n)
{
    ifstream fin("insurance.txt");
    fin >> n;
    Insurance** ins = new Insurance * [n];
    for (size_t i = 0; i < n; ++i) {
        char type;
        fin >> type;
        if (type == 'F') {
            ins[i] = new FamilyInsurance();
            fin >> *ins[i];
        }
        else if (type == 'C') {
            ins[i] = new CarInsurance();
            fin >> *ins[i];
        }
        else
        {
            string temp;
            getline(fin, temp);
        }
    }
    fin.close();
    return ins;
}
void printArr(Insurance** ins, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        ins[i]->print();
    }
}

double calculateTotalValue(Insurance** ins, size_t n) {
    double totalValue = 0.0;
    for (size_t i = 0; i < n; ++i) {
        totalValue += ins[i]->totalPrice();
    }
    return totalValue;
}



Insurance* findMostExpensive(Insurance** ins, size_t n)
{
    Insurance* mostExp = ins[0];
    for (size_t i = 1; i < n; i++)
    {
        if (*ins[i] > *mostExp) {
            mostExp = ins[i];
        }
    }

    return mostExp;
}

Insurance* findMostCheap(Insurance** ins, size_t n)
{
    Insurance* mostCheap = ins[0];
    for (size_t i = 1; i < n; i++)
    {
        if (*ins[i] < *mostCheap) {
            mostCheap = ins[i];
        }
    }

    return mostCheap;
}