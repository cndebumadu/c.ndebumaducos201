#include <iostream>
using namespace std;

int main() {
    cout << "write your name" << endl;
    string name;
    cin >> name;

    cout << "write your age" << endl;
    int age;
    cin >> age;

    if ( age >= 18) {
        cout << name << " is an adult " << endl;

    }
    else {
          cout << name << " is a child  " << endl;
    }



    return 0;
}