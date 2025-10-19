#include <iostream>

using namespace std;
int main() {
    cout << " what is the temperature in fahrenheit" << endl;
    double f;
    cin >> f;

    double celcius = ( (5 / 9) * (f -32));

    cout << " the temperature in celcuis is  " << celcius << endl;

    cout << " what is the temperature in celcius" << endl;
    double c;
    cin >> c;

    double fahrenheit = ( c * 1.8 ) + 32;

    cout << " the temperature in fahrenheit is  " << fahrenheit << endl;



   
    return 0;

}