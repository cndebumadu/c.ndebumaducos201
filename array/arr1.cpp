#include <iostream>
using namespace std;


int main(){
  
    const int size = 6;
    int array[size]={1,2,3,4,5,6};

    int userinput;
    cout<<"ENTER THE NUMBER"<<endl;
    cin>>userinput;

for(int i = 1;i<size;i++){
    if(i==userinput){
        cout<<"this is it :"<<i<<endl;
        return 0;
    }
    
}
cout<<"GET OUT,CANT FIND YOUR ITEM"<<endl;


}