#include <iostream>
using namespace std;

int main() {

    cout << " enter first number" << endl;
    int x;
    cin >> x;

    cout << "enter second number" << endl;
    int y;
    cin >> y;
    int temp;
    

    temp = x;
    x = y;
    y = temp;


    cout << " after swapping" << endl;
    cout << x << endl;
    cout << y << endl;

    return 0;
}