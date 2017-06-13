#include <iostream>
#include <iomanip>
using namespace std;
class Fraction
{
    int myNumerator, myDenominator;
    
public:
    void inFraction();
    void printFraction() const;
    int getNm();
    int getDm();
    void setNm(int numer);
    bool setDm(int denom);
    
};
void Fraction::printFraction() const
{
    cout << myNumerator << "/" << myDenominator << endl;
}
int Fraction::getDm()
{
    return myDenominator;
}