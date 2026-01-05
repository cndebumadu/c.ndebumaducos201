//File Handling in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream infile("data.txt");

    if(!infile){
        cout<< "File cannot be open.";
        return 0;
    }

    int number;
    int sum = 0;

    while(infile >> number){
        cout << number<< endl;
        sum = sum + number;
    }
    cout <<"The sum is "<< sum;
    infile.close();
}