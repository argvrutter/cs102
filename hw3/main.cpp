#include "iostream"
using namespace std;

int main()
{
    double volts, amps, watts;    

    cout << "Enter volts: ";
    cin >> volts;

    cout << "Enter amps: ";
    cin >> amps;

    watts = volts * amps;

    cout << volts << " volts and " << amps << " amps = " << watts << " watts." << endl;
    return 0;
}