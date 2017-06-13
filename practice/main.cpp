#include <iostream>
using namespace std;

bool passOrFail(int grade){
    if (!(grade < 70))
        return true;
    else
        return false;
    return 0;
}
int main(){
    int in;
    cout << "Enter your grade" << endl;
    cin >> in;
    if (passOrFail(in))
        cout << "You have passed";
    else
        cout << "You have failed";
    return 0;
}