/* AUTHOR: AIDAN RUTTER
 * DATE: 3/21/2017
 * ASSIGNMENT: CASE 4 - SILLY SENTENCES
 *
 * PURPOSE: Create four word sentences composed of an article, a noun, a verb
 * and an adverb. This is using arrays of predefined words. This will demonstrate
 * student's understanding of arrays, string manipulation, random number generators,
 * and creating functions.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

string pickWord(const string words[], int numWords);
string genSent();
void fixSent(string& sentence);
void printSent(string sentences[], int numSent);

const int NUMART = 4, NUMNOUN = 6, NUMVERB = 3, NUMADV = 4, NUMVOW = 5;
const string ARTICLES[] = { "The", "This", "A", "That" };
const string NOUNS[] = { "elephant", "tiger", "lion", "panther", "aardvark", "bear" };
const string VERBS[] = { "ate", "ran", "slept" };
const string ADVERBS[] = { "heartily", "fast", "upsidedown", "quickly" };
const char VOWELS[] = { 'a', 'e', 'i', 'o', 'u' };

int main()
{
    int seed, numSentences;
    string sentence = "";
    cout << "Enter a seed value for the random number generator ";
    cin >> seed;
    srand(seed);
    do {
    cout << "Enter the number of sentences to create (1-20)";
    cin >> numSentences;
    } while(!(numSentences > 0 && numSentences < 21));//checks to make sure numSentences is between 1 and 20
    cout << endl;
    string sentences[numSentences];
    for(int i = 0; i < numSentences; i++) {//loop which generates array of complete sentences
        sentence = genSent();
        fixSent(sentence);
        sentences[i] = sentence;
    }
    printSent(sentences, numSentences);
}
/*Purpose of pickWord: Takes in a word array, and returns a random word within it.
 * Arguments: const array of predefined words. Also an int representing the number of
 * elements in the array passed to it.
 * Return type: A string representing a random element from an array of words.
 */
string pickWord(const string words[], int numWords)
{
    return words[rand() % numWords];
}
/*Purpose of genSent: Using the previously defined pickWord function, generate
 * a sentence by concatenating an article, noun, verb, and adverb.
 * Arguments: None
 * Return type: String. This string is a sentence, before it has been corrected.
 */
string genSent()
{
    string sent;
    sent += pickWord(ARTICLES, NUMART) + " ";
    sent += pickWord(NOUNS, NUMNOUN) + " ";
    sent += pickWord(VERBS, NUMVERB) + " ";
    sent += pickWord(ADVERBS, NUMADV);
    return sent;
}
/*Purpose of fixSent: Add "n" to a when that is grammatically correct.
 * Also replaces the verb with a different verb is the article is A and the noun
 * does not start with a vowel.
 * Arguments: A call by-reference string that will be used to store a string of words.
 * Return type: void - returns nothing.
 */
void fixSent(string& sentence)
{
    int verbStart, verbEnd;
    string temp;
    bool vowel = false;
    if(sentence.at(0) == 'A') 
        {
            //if(sentence.at(2) == ('a'||'e'||'i'||'o'}))
        for(int i = 0; i < NUMVOW; i++) {//checks to see if the noun starts with a vowel
            if(sentence.at(2) == VOWELS[i]) {
                sentence.insert(1, "n");
                vowel = true;
                break;
            }
        }
        if(!vowel)  {
        verbStart = sentence.find(" ",(sentence.find(" ") + 1)) +1;
        verbEnd = sentence.rfind(" ") -1;
        temp = sentence;
        sentence.erase(verbStart,-1);
        sentence.insert(verbStart, pickWord(VERBS,NUMVERB) + temp.substr(verbEnd+1,-1));
    }
    }  
}
/*Purpose of printSent: Prints the array of sentences.
 * Arguments: Array of sentences, which are complete and created in the main function.
 * Return type: Void. Returns nothing.
 */
void printSent(string sentences[], int numSent)
{
    for(int i = 0; i < numSent; i++) {
        cout << sentences[i] << endl;
    }
}
