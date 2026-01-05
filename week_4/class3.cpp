#include <iostream>
using namespace std;

inline int triple(int num){
int triple= num * 3;

return triple;
}

int main(){
  int num1=3;
  int num2=4;
   int multiply1 = triple(3);
   int multiply2 = triple(4);

   cout<<"The triple of num1 is :"<<endl;
   cout<<multiply1<<endl;

  cout<<"The triple of num2 is :"<<endl;
   cout<<multiply2<<endl;

}