#include <iostream>

#include <iomanip>

 

using namespace std;

 
int getNumber(int min, int max);
 

int main()

{

        char ans;

        int seed;

 

        cout << "Enter seed: ";

        cin >> seed;

 

        srand(seed);

 

        do {

               int min, max;

               cout << endl;

               cout << "Enter minimum: ";

               cin >> min;

               cout << "Enter maximum: ";

               cin >> max;

 

               cout << endl << endl;

 

               getNumber(min, max);

               // The number printed below seems to always be the same and is

               // garbage!

               cout << "Random number = " << getNumber(min, max) << endl;

               cout << "New random number? ";

               cin >> ans;

             // loop while ans is not n or N

             } while (ans != 'n' || ans != 'N');

 

        return 0;

}

 

int getNumber(int min, int max)

{

       // should return numbers between min and max

        return min + (rand() % ((max + 1) - min));
        

}