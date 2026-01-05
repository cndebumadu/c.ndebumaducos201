#include <iostream>
using namespace std;



int sum(int arraysize,int array[]){
    int sum=0;

for(int i=0; i <arraysize;i++){


 sum+=array[i];

}
 return sum;

}

int product(int arraysize,int array[]){
    int product=1;

for(int i=0; i <arraysize;i++){


 product*=array[i];

}
 return product;

}


int main(){
const int size = 6;
int arr[size]={1,2,3,4,6,7};
int arraysum = sum(size,arr);
int arrayproduct = product(size,arr);
 cout<<arraysum<<endl;
  cout<<arrayproduct<<endl;

}