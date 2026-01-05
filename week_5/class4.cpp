#include <iostream>
using namespace std;

int main(){

    cout << " Input two number" <<endl;
    int x;
    int y;
    cin >> x >>  y;

    int add( int add1 , int add2) {
        add1 + add2;
    }

     int sub( int sub1 , int sub2) {
        sub1 + sub2;
     }

     int multi(int multi1 , int multi2){
        multi1 * multi2;
     }

      int div( int div1 , int div2) {
        div1 + div2;
      }

       int mod( int mod1 , int mod2) {
        mod1 + mod1; 
       }

      int result = add( x, y);
      cout << "the addition is" << result << endl;

   

    


    return 0;
}