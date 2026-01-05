#include <iostream>
using namespace std;

int main(){
  
    srand(time(0));

const int size =10;

int array[size]={};

for(int i =0 ; i<size ; i++){
int r = rand() % 21;
array[i] = r;

cout<<r<<",";

}



}