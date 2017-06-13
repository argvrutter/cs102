#include <iostream>
using namespace std;

int main()
{
    cin >> distance >>debt >>endl;

    trips = distance/((.0043)(1/12)(1/5280));
    cout <<fixed<<showpoint<<setprecision(3);
    cout << "\n\nYour debt travels " << debt * DOLLAR_BILL_THICKNESS << " inches\nor " << (debt * DOLLAR_BILL_THICKNESS) / 1. / 5280 << " miles.\n";
    cout << "\n\nWith a debt of " << debt << "\nand a distance of " << distance << ",\nyou can make " << trips << " trips." << endl;

   return 0;
}    
