#include <iostream>
using namespace std;
#include <cstdlib>   
#include <ctime>

int main(){
    cout << "Please enter your name"<< endl;
    string name;
    cin >> name;

    cout << " Are you a pau student " << endl
         << " enter 1 for yes and 0 for no" << endl;
    bool pau;
    cin >> pau;

    cout << " choose your courses " << endl
         << "Photography = 1" << endl
         << "Painting = 2" << endl
         << "Fish Farming = 3" << endl
         << "Baking = 4" << endl
         << "Public Speaking = 5" << endl;

    int courses;
    cin >> courses;     

    cout  << " choose your Location " << endl
         << "Campus house A = 1" << endl
         << "Campus house B = 2" << endl
         << "Campus house C= 3" << endl
         << "Campus house D= 4" << endl
         << "Campus house E = 5" << endl;  
    int location;
    cin >> location;
    int regfee;
    int day;
    string cname;

    switch(courses) {
        case 1 :
        cname = "Photography";
        regfee = 10000;
        day = 3;
        break;

        case 2 :
        cname = "Painting" ;
         regfee = 8000;
         day = 5;
        break;

        case 3 :
        cname = "Fish Farming" ;
       
         regfee = 15000;
         day = 7;
        break;

        case 4 :
        cname = "Baking" ;
         regfee = 13000;
         day = 5;
        break;

        case 5 :
        cname = "Public Speaking" ;
         regfee = 5000;
         day = 2;

        break;

        default :
        cout << "invalid number try again" << endl;

    }  
    int lpd;
    string chouse;


    switch(location) {
        case 1 :
        chouse = "Camp House A";
        lpd = 10000;
        break;

        case 2 :
         chouse = "Camp House B";
         lpd = 2500;
        break;

        case 3 :
         chouse = "Camp House C";
         lpd = 5000;
        break;

        case 4 :
         chouse = "Camp House D";
         lpd = 13000;
        break;

        case 5 :
         chouse = "Camp House E";
         lpd = 5000;
        break;

        default :
        cout << "invalid number try again" << endl;

    }  
int lodgingCost = lpd * day;



if ( pau == 1 && (location == 1 || location == 2 ) ) {
    lodgingCost = lodgingCost * ( 1 - 0.005);

}

if ( day > 5 || regfee > 12000) {

    regfee = regfee * (1 - 0.03);
}
int total = regfee + lodgingCost; 
int promo = 500;

srand(time(0));
int r;
r = rand() % 101;
if (r == 7 || r == 77) {
    total = total - promo;
}

cout << name << endl
    << "course: " << cname << "  days : " << day << endl
    << "Registration: " << "₦" << regfee << endl
    << "Lodging: " << "₦" << lpd << " * " << day << " = " << lodgingCost << endl
    << "Random Draw: " << r << " Promo Applied: " << "₦" << promo << endl
    << " TOTAL: " << "₦" << total << endl;






    
    
    
    
    
    
    return 0;

}