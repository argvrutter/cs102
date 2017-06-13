#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cout << "Enter three numbrs";
    cin >>a>>b>>c;
    
    if ((a<b)&&(a<c))
        cout << "true my dude";
    else
        cout << "nah";
    return 0;
}