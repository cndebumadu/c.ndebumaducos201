//Write a C++ function named ‘sum’ that takes two integers as parameters and returns their sum.
//Use this function in ‘main()’ to add two numbers input by the user.
//Define a function called ‘square’ that takes an integer as input, returns the square of that number, and call it from ‘main()’.


#include <iostream>
using namespace std;

int sum(int num1 , int num2){
int sum = num1 +  num2;
return sum;
}

double square(int num3){
    double square=num3 * num3;

    return square;
}
int main(){
    int num1;
    int num2;
    int num3;

cout<<"ENTER NUM1"<<endl;
cin>>num1;

cout<<"Enter num2: "<<endl;
cin>>num2;
cout<<"The sum of num 1 and num2 is :"<<endl;

int add=sum(num1,num2);
cout<<add<<endl;;
cout<<"Enter the num3 you would like to square:"<<endl;
cin>>num3;

cout<<"The square of num3 is :"<<endl;
int multiply = square(num3);
cout<<multiply;
}