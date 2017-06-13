#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char whatevs = 'y';
    int dataset, num, sum, min = 99999, max = 0, avgDenom = 0;
    bool prime = true, zero = false;
    double average;
    while(whatevs == 'y') {//encapsulation lvl 1: all vars constant during whole data set stored here, reset after n
        cout << "How many numbers in your data set?";
        cin >> dataset;
        zero = false;
        min = 99999;
        max = 0;
        avgDenom = 0;
        sum = 0;
        average = 0;//inefficiently resetting all the variables
        for(int i = dataset; i > 0; i--) {//encapsulation lvl 2: all calcs for singular data set
            prime = true;
            cout << "Enter a number in your data set: ";
            cin >> num;
            sum += num;
            avgDenom++;
            
            if(num == 0)
                zero = true;
                
            if(num > max)
                max = num;
            if(num < min)
                min = num;

            if(num % 2 == 0)
                cout << num << " is even";
            else 
                cout << num << " is odd";
            for(int k = 2; k < num; k++) {
                    if(num % k == 0) {
                        prime = false;
                    }
                }
            if(prime)
                cout << num << " is a prime number";
            
            if(!prime) {
                cout << num << " is divisible by ";
                for(int j = 2; j < num; j++) {
                    if(num % j == 0) {
                        cout << j << " ";
                    }
                }
            }
            
        }
        if(!zero)
            average = double(sum) / double(avgDenom);
        else
        {
            average = 0;
            sum = 0;
            min = 0;
            max = 0;
        }
        
        cout << "The sum is " << sum << " and the average is " << fixed << setprecision(0) << average;
        cout << "The min is " << min << " and the max is " << max;
        cout << "Do you want to do another data set? ";
        cin >> whatevs;
    }
}