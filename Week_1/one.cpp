#include <iostream>

using namespace std;
int main() {
    double x;
    double y;

    cout << "enter first number" << endl;
    cin >> x;

    cout << "enter secong number" << endl;
    cin >> y;

    double sum = x + y;
    double product = x * y;
    double diff;

    if ( x > y) {
         diff = x - y;
        
    }
    else {
         diff = y - x;
    }
        
    
    cout << " the sum is : " << sum << endl;
    cout << " the product is : " << product << endl;
     cout << " the difference is " << diff << endl;
    
    




    

    return 0;
}