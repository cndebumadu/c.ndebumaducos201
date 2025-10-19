#include <iostream>
using namespace std;

int main() {

    cout << " what is the total purchase amount" << endl;
    double amount;
    cin >> amount;

    double salesTax = amount * 0.06;

    cout << " the sales tax is = " << salesTax << endl;
    cout << " the purchase amount is = " << amount << endl;



    return 0;
}