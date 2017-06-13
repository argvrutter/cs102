#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
//variable declarations
char edlevel, screensize;
int mentSharp, age;
double ppi, adjppi;
string inputDevice;
const double adjk = 1.0, adjm = .60, adjf = .85; //creates constants for keyboard, mouse, and finger adjustments.

int main() {
cout << "CSOZT Brain Trainer " << endl << endl;
//take in input variables (phase 1)
cout << "Education level (a, c, or h): "; 
cin >> edlevel; 

cout << "Mental sharpness (1-10): ";
cin >> mentSharp;

cout << "Age (in years): ";
cin >> age;
// input variables (phase 2)
cout << "Input device (keyboard, mouse, finger): ";
cin >> inputDevice;

cout << "Screen size (d, l, p, t): ";
cin >> screensize;
//ppi calculations

if (edlevel == 'h' || mentSharp <=3)
    ppi = 4.72*(455+ (6.8*mentSharp*mentSharp))/(2.1*age);
else if (edlevel == 'c')
    ppi = 5.25 * (383.0 + (7.3 * mentSharp * mentSharp)) / (1.9 * age);
else if (edlevel == 'a')
    ppi = 5.73 * (573.0 + (7.9 * mentSharp * mentSharp)) / (1.75 * age);

// calculations for adjusted ppi
if (inputDevice == "keyboard")
    adjppi = ppi * adjk;
else if(inputDevice == "mouse")
    adjppi = ppi * adjm;
else if(inputDevice == "finger")
    adjppi = ppi * adjf;
else
    {
    cout << "invalid input device";
    return 0;
    }
//switch statements that change the adjusted PPI based on the case. if character doesn't match one of the cases, it will say invalid display.
switch(screensize){
case('d'): {adjppi = 1.0*adjppi;break;}
case('l'): {adjppi = 1.1*adjppi; break;}
case('p'): {adjppi = 1.4*adjppi; break;}
case('t'): {adjppi = 1.25*adjppi; break;}
default: cout << "invalid screen type";
return 0;
}
cout <<endl<<endl<< "PPI = " << round(ppi) << endl;
cout << "Adjusted PPI = " <<fixed<< setprecision(2)<<adjppi;
return 0;
}