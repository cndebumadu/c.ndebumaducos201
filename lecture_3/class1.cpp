#include <iostream>
using namespace std;



int main(){

int total;
int count;
int positive_count;
int negative_count;


while(true){
    int n;

    cout<<"Enter a number";
    cin>>n;
    if (n<0){
        negative_count++;

    }
    else if(n>0){
        positive_count++;

    }
     else{
       break;



    }
    total+=n;
count++;
}

double average= static_cast<double>(total)/count;
cout<<"Total"<<total<<endl;
cout<<"Count"<<count<<endl;
cout<<"Average"<<average<<endl;
cout<<"Positive_count"<<positive_count<<endl;
cout<<"Negative_count"<<negative_count<<endl;
}