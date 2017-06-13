//A program that calculates heart rates depending on age

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    
    // User enters first and last name 
    string first;
    string last;

    int age;
    double athletic_pulse;
    double fatburn_pulse;
    // set up the coeffients 
    const double FAT_COEFFICIENT = 2.04;
    const double ATH_COEFFICIENT = 2.97;

    cout << "Maximum Pulse Calculator" << endl;
    cout << "Enter first and last name: ";
    cin >> first >> last;

    cout << "Enter your age: ";
    cin >> age;

    // This section should calculate the following 
    // 1. Subtract age from 100
    // 2. Multiple #1 by ***_COEFFICIENT
    fatburn_pulse = (100 - age) * FAT_COEFFICIENT;
    athletic_pulse = (100 - age) * ATH_COEFFICIENT;

    // I want the last name and the first name
    // to each be in a field, right-justified, 10 characters wide wide. 
       //  there should be a comma and space after the last name before the first name 
    cout << right << setw(10) << last << right << ", " << setw(10) << first << endl;

    cout << "For a " << age << " year old:" << endl;

    //S: These should each be in fixed notation and only 1 decimal point of precision
    
    cout << "\tFatburn Pulse = " << setprecision(1) << fatburn_pulse << endl;
    cout << "\tAthletic Pulse = " << setprecision(1) << athletic_pulse << endl;

    return 0;

}