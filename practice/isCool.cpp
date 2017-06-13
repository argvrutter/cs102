#include <iostream>
using namespace std;
//"If you chose tea instead of coke, you are cool"
int main(){
    bool choseTea = false, choseCoke = false;
    bool cool;
    int choice;
    
    cout << "What drink did you choose? 1 for tea, 2 for coke, 3 for other.";
    cin >> choice;
    switch(choice){
        case(1): {choseTea = true; break;}
        case(2): {choseCoke = true; break;}
    }
    
    if(choseTea && !coke)
    {
        cool = true;
    }
    
    if(cool)
        cout << "You are cool.";
    else
        cout << "although this is based on a positive statement, you have not met the required conditions to be considered cool."
}