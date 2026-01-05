#include <iostream>
using namespace std;
#include <cstdlib>   
#include <ctime>

int main(){
 // input
    cout << "What is your full name"<< endl;
    string fullname;
    cin >> fullname;

    cout << "What is your JAMB score" << endl;
    int jamb;
    cin >> jamb;

    cout<< "What is your WAEC average" << endl;
    int waec;
    cin >> waec;

    cout << " What is your Age" << endl;
    int age;
    cin >> age;

    cout << "Was PAU your first choice 1 = yes and 0 = no" << endl;
    bool firstchoice;
    cin >> firstchoice;

    cout << " do you have any disciplinary records 1 = yes  0 = no" << endl;
    bool dr;
    cin >> dr;

    cout << "what hostel do you prefer" << endl
    << "1 - Main hostel(180,000)" << endl
    << "2 - Amex hostel(120,000)" << endl
    << "3 - Day student(0)" << endl;
    string ha;
    int hostelfees;
    int hostel;
    cin >> hostel;

    int basetuition = 1500000;
    string accept;

 // addmision gateway
    if (( jamb >= 220 && waec >= 60 && firstchoice == 1) || ( jamb >= 200 && waec >= 70 )) {
        if ( dr == 1 || age < 15) {
            accept = "rejected";
        }
        else {
            accept = "admit";
        }
       
    }

    else {
      accept = "pending";  
    }
    string scholarship;

  // schlarship do loop
  if ( accept == "admit"){
  
    if ( jamb >= 320){
        scholarship = "30%";
    basetuition = basetuition - (basetuition * 0.3);
   }
   else if ( jamb >=300 && jamb < 320){
    scholarship = "25%";
    basetuition -= basetuition*0.25;
   }

   else if ( jamb >= 280 && jamb < 320){
    scholarship = "20%";
    basetuition = basetuition - (basetuition * 0.2);
   }

   else if (jamb >= 240 && jamb < 280){
    scholarship = "10%";
    basetuition = basetuition - (basetuition * 0.1);
   }
   else {
    scholarship = "0%";
    basetuition = basetuition;
   }
  }

// bonus rule
   if (waec >= 80 && firstchoice == 1){
    basetuition = basetuition - (basetuition * 0.05);
   }

// hostel assignment
  if ( accept == "admit") {
    switch (hostel){
        case 1 : 
        ha = "main hostel";
        hostelfees = 180000;
        break;

        case 2 :
        ha = "amex hostel";
        hostelfees = 120000;
        break;

        case 3 :
        ha = "day student";
        hostelfees = 0;
        break;

        default :
         ha = "no hostel match";
    

    }

    // random merit grant
    srand(time(0));
    int r;
    r = rand() % 101;
    int total;
    total = basetuition + hostelfees;
    string merit ;

    if ( r % 2 == 0 && r < 97){
       
        merit = "50,000";
        total = total - 50000;
    }

    // output
    cout << "Name:" << fullname << endl
    << "Admission Status:" << accept << endl
    <<"Scholarship  "<< scholarship << endl
    << "tuition after scholarship " << basetuition<<endl
    << ha << endl
    << "random draw " << r << "  Merit grant" << merit<< endl
    << "TOTAL PAYABLE:" << total;



    return 0;

    


  }

        
    
    






    



    


    





    return 0;
}