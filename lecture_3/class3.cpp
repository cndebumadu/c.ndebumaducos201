#include <iostream>
using namespace std;

int main(){
   int count;
   cout<<"Enter number of items"<<endl;
   cin>>count;
   
   string items[count];
 int prices[count];
  for(int i= 0; i<count;i++){
   
   cout<<"Enter the name of the item"<<endl;
  cin>>items[i];
   
 
  cout<<"Enter the price of the item"<<endl;
  cin>>prices[i];
 }

int lowestprice;
string lowestitem;
for(int i =0;i<count;i++){
 

 if(prices[i] < lowestprice){
    

 }
}
}