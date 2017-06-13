#include <iostream>

#include <string>

#include <iomanip>

 

using namespace std;

 

const double TAX_RATE_LOW = 0.10;

const double INCOME_LOW = 15000.0;

 

const double TAX_RATE_MED = 0.15;

const double INCOME_MED = 35000.0;

 

const double TAX_RATE_HI = 0.20;

 

int main()

{

        double income;

        double tax;

        char run = 'y';

 

        // This program should run as long as the user types y

        // Hint is there a better loop?

        while (run == 'y') {

               cout << "Enter your income for this year: ";

               cin >> income;


 
               cout << endl;

 

        // This doesn’t work

               if (income <= INCOME_LOW) {

                       tax = income * TAX_RATE_LOW;

               }

               else if (income <= INCOME_MED) {

                       tax = income * TAX_RATE_MED;

               }

               else if (income > INCOME_MED) {

                       tax = income * TAX_RATE_HI;

               }

 

        // output the normal "dollars" with 2 decimal points of precision

               cout << "You owe $" << fixed << setprecision(2) << tax << " in taxes." << endl;

 

               cout << "Do you want to run another tax calculation? ";

               cin >> run;

               cout << endl << endl;

        }

        return 0;

}

