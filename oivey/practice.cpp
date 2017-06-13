#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int getValue(int j, int k) {       return j % k;
}

int main() {
    cout << getValue(30, 11);
}