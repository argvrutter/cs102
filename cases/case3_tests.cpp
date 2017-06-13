/* AUTHOR: AIDAN RUTTER
 * DATE: 2/24/2017
 * ASSIGNMENT: CASE 3 - BLACKJACK!
 *
 * PURPOSE: CREATE A GAME OF BLACKJACK THROUGH THE USE OF
 * FUNCTIONS, LOOPS, AND RANDOM NUMBER GENERATORS. LEARN HOW
 * TO CREATE AND USE YOUR OWN FUNCTIONS.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;

int drawCard();
int genHand(string name);
int addCard(string name, int total);

int main(){
    int totalPlayer, totalDealer, seed, numHands, playerWins = 0, dealerWins = 0;
    string playerName;
    char y = 'y';

    cout << "Enter a seed value for the random number generator: ";
    cin >> seed;
    srand(seed);
    cout << endl << "Enter your name: ";
    cin >> playerName;
    cout << endl << playerName << ", how many hands would you like to play?";
    cin >> numHands;
}
int drawCard()
{ // draws a card between 1 and 52, then assigns card a face value.
    int card;
    card = ((rand() % 51) + 1);
    card = (card / 51.0) * 13 + 1;
    if(card > 10)
        card = 10;

    return card;
}
int genHand(string name)
{ // generates your hand, draws 2 cards and returns the value of the hand.
    int card1 = drawCard(), card2 = drawCard();
    cout << name << " first card is a " << card1 << endl;
    cout << name << " second card is a " << card2 << endl;
    cout << name << " total points are " << card1 + card2 <<endl;
    return card1 + card2;
}
int addCard(string name, int total)//takes in total, draws a card and returns the new total
{
    int card = drawCard();
    cout << name << " drew a " << card << endl;
    total += card;
    cout << name << " total points are " << total <<endl;
    return total;
}