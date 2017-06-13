//Program which returns change. As
#include <iostream>// importing libraries duh
using namespace std;

int main() { 
    double cost, money, change;
    cout << "enter cost $";//prompts for input
    
    cin >> cost;//cin -> waits for input, receives it
    
    cout << "Enter money $";// think of arrows as the way that the data moves (in small side, out big side.)
    cin >> money;
    change = money-cost;
    cout << "Change = $" << change << endl;
    
    return 0;// method is done
}