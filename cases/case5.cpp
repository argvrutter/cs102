/*AUTHOR: AIDAN RUTTER
 * DATE: 3/29/17
 * ASSIGNMENT: CASE 5 - THE CRIME SCENE!
 *
 * PURPOSE: READ VALUES RELATED TO CRIME RATES INTO VECTORS FROM A FILE.
 * THIS DATA WILL BE MANIPULATED AND PRESENTED IN VARIOUS WAYS. THIS WILL GIVE STUDENTS
 * EXPERIENCE WITH CONCEPTS SUCH AS VECTORS, FILE I/O, STRING STREAMS, I/O MANIPULATORS,
 * AND CREATING FUNCTIONS.
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

string toLower(string district);
int getDistrict(string district, vector<string> districts);
void printSummary(vector<int> nv, vector<int> v, vector<int> dv, vector<string> districts, vector<int> history);
int max(vector<int> a);
int min(vector<int> a);

int main(int argc, char* argv[])
{
    vector<string> districts;
    vector<int> nv, v, dv, history;
    ifstream fin;
    istringstream sin;
    double a, b, c;
    string line, d, eval;
    int temp, temp2;

    fin.open(argv[1]);

    if(fin.fail()) {
        cout << "Failed to open document";
        return -1;
    } else if(argv[2] == NULL) {
        cout << "Requires a file and number of burrows to print";
        return -1;
    }
    while(getline(fin, line)) {//reads values of file into vector array
        sin.clear();
        sin.str(line);
        sin >> d >> a >> b >> c;
        districts.push_back(d);
        nv.push_back((int)(a * 10.0));
        v.push_back((int)(b * 10.0));
        dv.push_back((int)(c * 10.0));
    }
    // cout << "First command Line: " << argv[1] << endl;
    // cout << "Second Command Line: " << argv[2] << endl;
    sin.clear();
    sin.str(argv[2]);
    sin >> temp2;
    cout << "Top ";
    if(temp2 > districts.size())
        cout << districts.size() << " Crime Ridden Areas In Baltimore" << endl;
    else
        cout << temp2 << " Crime Ridden Areas In Baltimore" << endl;
    cout << left << fixed << setw(25) << "District" << " ";
    cout << left << setw(4) << fixed << "VC" << " ";
    cout << left << setw(4) << fixed << "DV" << " ";
    cout << left << setw(4) << fixed << "NVC" << endl << endl;

    
    for(int i = 0; i < temp2 && i < districts.size(); i++) {//formats and prints districts of highest crime
        cout << left << fixed << setw(25) << districts[i] << " ";
        cout << left << fixed << setw(4) << v[i] << " ";
        cout << left << fixed << setw(4) << dv[i] << " ";
        cout << left << fixed << setw(4) << nv[i] << endl;
    }
   cout << endl;
   
    while(!(eval == "done")) {//continues to execute until user enters done
        sin.clear();
        cout << "Enter a district:                           "; 
        cin >> eval;
        eval = toLower(eval);
        if(eval == "Done")
            break;
        temp = getDistrict(eval, districts);
        if(temp != -1) {
            history.push_back(temp);
            cout << left << fixed << setw(4) << "VC" << " ";
            cout << left << fixed << setw(4) << "DV" << " ";
            cout << setw(4) << left << fixed << "NVC" << endl;
            cout << setw(25) << left << fixed << toLower(districts[temp]) << " ";
            cout << setw(4) << left << fixed << v[temp] << " ";
            cout << setw(4) << left << fixed << dv[temp] << " ";
            cout << setw(4) << left << fixed << nv[temp] << endl << endl;

        } else {
            cout << setw(4) << left << fixed << "VC" << " ";
            cout << setw(4) << left << fixed << "DV" << " ";
            cout << setw(4) << left << fixed << "NVC" << endl;

            cout << setw(25) << left << fixed << eval << " ";
            cout << setw(4) << left << fixed << "----" << " ";
            cout << setw(4) << left << fixed << "----" << " ";
            cout << setw(4) << left << fixed << "----" << endl << endl;
        }
    }
    cout << endl;
    printSummary(nv, v, dv, districts, history);
    fin.close();
}
/*Purpose of getDistrict: Searches through all the districts and finds the index value of the given district
 * Arguments: String representing the search value, followed by the vector with the information about districts
 * Return type: integer representing the index of the searched for string. If it wasn't found, it
 * returns -1.
 */
int getDistrict(string district, vector<string> districts)
{
    district = toLower(district);
    string temp;
    for(int i = 0; i < districts.size(); i++) {
        temp = districts.at(i);
        districts.at(i) = toLower(temp);
        if(districts.at(i) == district)
            return i;
    }
    return -1;
}
/*Purpose of toLower: This function will convert any string into a lowercase string
 * by converting to a c-style string, converting each individual character to
 * lowercase, then converting it back to a string and returning it.
 * Arguments: c++ style string to be converted to lowercase.
 * Return type: lowercase C++ style string
 */
string toLower(string district)
{
    int i=0;
    while(i < district.size())
    {
        district[i] = tolower(district[i]);
        i++;
    }
    district[0] = toupper(district[0]);
    
    return district;
}

/* Purpose of printSummary: Prints a politician's summary that includes the districts of the
 * highest crime rate of each category
 * Arguments: All of the vectors containing data from the text file. This is neccesary to
 * retrieve and manipulate the data.
 * Return type: void - this function only prints to the console.
 */
void printSummary(vector<int> nv, vector<int> v, vector<int> dv, vector<string> districts, vector<int> history)
{
    for(int i=0; i<history.size();i++)//removes vector items not in history
    {
        nv[i] = nv[history[i]];
        v[i] = v[history[i]];
        dv[i] = dv[history[i]];
        districts[i] = districts[history[i]];
    }
    nv.resize(history.size());
    v.resize(history.size());
    dv.resize(history.size());
    districts.resize(history.size());

    cout << "Highest Nonviolent Crime: " << districts[max(nv)] << endl;
    cout << "Lowest Nonviolent Crime : " << districts[min(nv)] << endl << endl;
    cout << "Highest Violent Crime: " << districts[max(v)] << endl;
    cout << "Lowest Violent Crime : " << districts[min(v)] << endl << endl;
    cout << "Highest Domestic Crime: " << districts[max(dv)] << endl;
    cout << "Lowest Domestic Crime : " << districts[min(dv)];
}
/* Purpose of max: Given a vector, returns the index of the max value.
 * Arguments: integer vector
 * Return type: integer representing index of max value
 */ 
int max(vector<int> a)
{
    int max = a[0], iMax = 0;
    for (int i = 0; i < a.size(); i++)
    {
      if (a[i] > max)
        {
          max = a[i];
          iMax = i;
        }
    }
    return iMax;
}
/* Purpose of min: Given a vector, returns the index of the min value.
 * Arguments: integer vector
 * Return type: integer representing index of min value
 */ 
int min(vector<int> a)
{
    int min = a[0], iMin=0;
    for (int i = 0; i < a.size(); i++)
    {
      if (a[i] < min)
        {
          min = a[i];
          iMin = i;
        }
    }
    return iMin;
}