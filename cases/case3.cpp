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

const int NUMCARDS = 52;
int main()
{
    int totalPlayer, totalDealer, seed, numHands, playerWins = 0, dealerWins = 0;
    string playerName;
    char y = 'y';

    cout << "Enter a seed value for the random number generator: ";
    cin >> seed;
    srand(seed);
    cout << "Enter your name: ";
    cin >> playerName;
    cout << playerName << ", how many hands would you like to play?" << endl;
    cin >> numHands;

    for(int i = 0; i < numHands; i++) // outermost loop, iterates and starts a new hand.
    {
        totalPlayer = genHand(playerName);
        cout << endl;
        totalDealer = genHand("Dealer");
        while(totalPlayer <= 21) { // loop which deals additional cards for the player
            cout << playerName << ", do you want to draw another card? (y/n) " << endl;
            cin >> y;
            if(y == 'y')
                totalPlayer = addCard(playerName, totalPlayer);
            else
                break;
            
        } // Loop for the dealer. continues to add cards if below 16 and player has not busted
        while(totalDealer < 16 && totalPlayer < 22) {
            totalDealer = addCard("Dealer", totalDealer);
        }
        cout << endl << endl << "The Result" << endl;
        cout << playerName << ": has " << totalPlayer << " points" << endl;
        cout << "Dealer: has " << totalDealer << " points" << endl;
        if(totalPlayer > 21) {
            dealerWins++;
            cout << playerName << ": lose" << endl << endl;
        } else if(totalDealer > 21) {
            playerWins++;
            cout << playerName << ": win!" << endl << endl;
        } else if(totalPlayer > totalDealer) {
            playerWins++;
            cout << playerName << ": win!" << endl << endl;
        } else {
            dealerWins++;
            cout << playerName << ": lose" << endl << endl;
        }
    }
    cout << "The Recap" << endl;
    cout << playerName << ": won " << playerWins << " games" << endl;
    cout << "Dealer: won " << dealerWins << " games" << endl;
    return 0;
}
/*Purpose of drawCard: Using rand, draws a random card, assigns it a face value, and returns it.
 * Arguments: None
 * Return type: int representing face value of card.
 */
int drawCard()
{
    int card;
    card = (rand() % NUMCARDS);
    card = card - ((card - 36) * (card / 36));
    card = card / 4 + 1;
    return card;
}
/*Purpose of genHand: Draws two cards at the beginning of a hand. Returns the total value of
 * the hand so that it can be used by the main function.
 * Arguments: String name, so that its output can use the playername acquired in the main function
 * Return type: int representing the total value of the players hand
 */
int genHand(string name)
{
    int card1 = drawCard(), card2 = drawCard();
    cout << name << ": first card is a " << card1 << endl;
    cout << name << ": second card is a " << card2 << endl;
    cout << name << ": total points are " << card1 + card2 << endl;

    return card1 + card2;
}
/*Purpose of addCard: Takes in the total and adds an additional card to
 * the value of the hand.
 * Arguments: Takes in the name of the player(string) and a hand's total value(int)
 * Return: returns an int representing the new total value of the hand.
 */
int addCard(string name, int total)
{
    int card = drawCard();
    cout << name << ": drew a " << card << endl;
    total += card;
    cout << name << ": total points are " << total << endl;
    return total;
}