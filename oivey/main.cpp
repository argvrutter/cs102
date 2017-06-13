#include <iostream>
using namespace std;
int main() { 
    char gender;
    int fcount = 0, mcount = 0;
    cout <<"Enter the gender";
    cin >> gender;
    if (gender == 'F')
        fcount++;
    else
        mcount++;
    cout << "The number of females " <<fcount <<" and males " << mcount<<endl;
    return 0;
}