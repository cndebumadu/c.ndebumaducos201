#include <iostream>
using namespace std;


void printGrade(int scores){

if (scores>=70 || scores<=100){
cout<<"A"<<endl;
}
else if (scores>=60 || scores<=69){
  cout<<"B"<<endl;  
}
else if (scores>=50 || scores<=59){
   cout<<"C"<<endl; 
}
else if (scores>=45 || scores<=49){
  cout<<"D"<<endl;  
}
else if (scores<45){
    cout<<"F"<<endl;
    
}
}
int main(){
int scores;
cout<<"enter your score :"<<endl;
cin>>scores;

cout <<"YOUR SCORE IS";
printGrade(scores);


return 0;

}