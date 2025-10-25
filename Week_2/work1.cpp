#include <iostream>
using namespace std;

int main() {
    cout << "write a number" << endl;
    int x;
    cin >> x;

    if ( x % 5 == 0){
        cout << "HIFive" << endl;

    }
    
    else if ( x % 2 == 0) {
        cout << " HIEven" << endl;
    }
    else  {
        cout << " none " << endl;
    
    }
    
    
    
    return 0;

}