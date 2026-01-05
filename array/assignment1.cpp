#include <iostream>
using namespace std;

//TO CALCULATE MAX AND MIN OF ARRAY
int main(){
    
   const int size = 6;
   int numbers[size]={4,5,6,7,8,9};


     int minimum =numbers[0];
     int maximum =numbers[0];
    

for( int i = 0; i <size ; i++){
    if(minimum > numbers[i]){
        minimum = numbers[i];
    }
    if(maximum< numbers[i]){
        maximum = numbers[i];
    }
}

cout<<"MAX :"<<maximum<<endl;
cout<<"MIN :"<<minimum<<endl;

}