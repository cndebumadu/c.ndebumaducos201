#include <iostream>
using namespace std;
#include <cstdlib>   
#include <ctime>

int main() {

    srand(time(0));
    int number1 =  rand() % 10;
    int number2 = rand() % 10;

    if ( number1 < number2) {
        int temp = number1;
        number1= number2;
        number2 = temp;
    }

    int diff = number1 - number2;

    cout << " what is the difference?" << endl;
    int answer;
    cin >> answer;

    if ( answer == diff) {
        cout << " correct "<< endl;
    }
    else {
        cout << "wrong" << endl;
    }



    return 0;
}