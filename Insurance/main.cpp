#include <iostream>
#include "insurance.h"

using namespace std;

int main()
{
    size_t n;
    Insurance** ins = createArr("11.txt", n);
    printArr(ins, n);
    cout << "Total af all insurances = " << calculateTotalValue(ins,n) << endl;

    cout << "The most expensive is =  ";
    findMostExpensive(ins, n)->print();
    cout << endl;
    cout << "The most cheap is =  ";
    findMostCheap(ins, n)->print();
    cout << endl;

    system("pause");
    return 0;
}