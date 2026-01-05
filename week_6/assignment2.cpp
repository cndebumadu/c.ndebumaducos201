#include <iostream>
using namespace std;
#include <cstdlib>   
#include <ctime>

void displaymenu(){
        cout << "What action do you want to carry out" << endl
    << "View balance = 1"<< endl
    << " deposit cash = 2" << endl
    << " Withdraw cash = 3" << endl
    << "Reset PIN = 4" << endl
    << "Exit = 5" << endl
    << "Enter your choice" << endl;
        
    }

    double viewBalance(double balance){
       cout << "your balance is " << balance <<endl; 
    return balance;

    }

    double depositwmoney(double balance){
        cout << " What amount do you want to deposit"<< endl;
        int deposit;
        cin >>  deposit;
        balance = balance + deposit;
        return balance;
    }

    double withdrawmoney(double balance, double dailylimit){
        double amount;

        cout << "enter the amount to withdraw: "<< endl;
        cin >> amount;

        if (amount> balance){
            cout << "insufficient balance" << endl;
            return balance;

            if (amount > dailylimit){
                cout << " Amount exceeds dailt withdrawal limit"<< endl;
                return balance;
            }

        }
        else {
            balance -= amount;
            return balance;
        }


        
    }


    int resetPin(int currentPin) {
    int oldPin, newPin, confirmPin;

    cout << "Enter your current PIN: ";
    cin >> oldPin;

    if (oldPin != currentPin) {
        cout << "Incorrect PIN! PIN reset failed." << endl;
        return currentPin; 
    }

    cout << "Enter your new PIN: ";
    cin >> newPin;

    cout << "Confirm your new PIN: ";
    cin >> confirmPin;

    if (newPin != confirmPin) {
        cout << "PINs do not match! PIN reset failed." << endl;
        return currentPin; 
    }

    cout << "PIN successfully updated!" << endl;
    return newPin; 
}

int main(){
    int accountbalance = 50000;
    int pin = 4321;
    int epin;
    int dailylimit = 20000;
    // if the pin is corret sha

    int attempts = 0;
    bool authenticated = false;
    while (attempts < 3 && !authenticated) {
        cout << "Enter your PIN: ";
        int enteredPin;
        cin >> enteredPin;
        if (enteredPin == pin) {
            authenticated = true;
        } else {
            cout << "Incorrect Pin" << endl;
            attempts++;
        }
    }

    if (!authenticated) {
        cout << "Too many incorrect attempts" << endl;
        return 0;
    }
        

    // atm menu
      int action;
     

    do {
        displaymenu();
        
        cin >> action;

        switch (action){
            case 1 :
            viewBalance(accountbalance);
            break;

            case 2 :
            depositwmoney(accountbalance);
            break;

            case 3 :
            withdrawmoney(accountbalance, dailylimit);
            break;

            case 4 :
            resetPin(pin);
            break;

            default :
            cout << "not part of the menu"<< endl;




        }
        
    }while ( action != 5);

    return 0;

    



   
}