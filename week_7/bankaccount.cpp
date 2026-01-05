#include <iostream>
using namespace std;

class bankaccount {
    public:
     string name;
     double balance;

    void withdraw(double w){
        
        balance = balance - w;
        

    }

    void deposit(double d) {
        
        balance = balance + d;
        

    }

    void checkbalance(){
        cout << "your account balance is" << balance <<endl;
    }
};

int main()
{  int password1;
    int password2;
    int password3;
    
    
    do {cout << "enter your password ( numbers only )"<< endl;
     cin >> password1;

    cout << " confirm your password" << endl;
    cin >> password2;

} while ( password1 != password2);

do {cout << " password " << endl;
    cin >> password3;

}while( password3 != password2);
cout << " correct you may continue" << endl;
    
    
    
    
    
    
    
    
    bankaccount account1;
    cout << " what do you want your account name to be ?" << endl;
    cin >> account1.name;
    account1.balance = 0;
    int x;

    do {
        cout  << "What function do you want to perform" << endl
        << "withdraw = 2 " << endl
        << " deposit = 3" << endl
        << " end banking process = 4" << endl
        << " check your balance = 5" << endl;
        cin >> x;

        if ( x == 2){ 
            cout << " how much do you want to withdraw" << endl;
            double z;
            cin >> z;
            account1.withdraw(z);
            cout << "your new balance is " << account1.balance << endl;

        }

        else if (x == 3){
            cout << " how much do you want to deposit" << endl;
            double t;
            cin >> t;
            account1.deposit(t);
            cout << "your new balance is " << account1.balance << endl;

        }

        else if (x == 5){
            cout << "your account balance is " << account1.balance << endl;
        }

        else if ( x == 4){
            cout << " thank you for banking with us" << endl;
        }

    

    } while ( x != 4);




    return 0;
}