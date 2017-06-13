/* AUTHOR: AIDAN RUTTER
 * DATE: 4/15/17
 * ASSIGNMENT: CASE 6: LET'S GO SHOPPING!
 *
 * PURPOSE: READ INFORMATION ABOUT SHOPPERS FROM A FILE, THEN OUTPUT A SUMMARY OF
 * THEIR SHOPPING HABITS TO ANOTHER FILE. THIS CASE PROVIDES EXPERIENCE WITH FILE I/O,
 * I/O MANIPULATORS, COMMAND LINE ARGUMENTS, AND CLASSES.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;
// shopping item class
class ShoppingItem
{
    int quantity;
    double cost;
    string name, first, last;

public:
    ShoppingItem();
    ShoppingItem(int _qty, double _cost, const string& _name);
    int getQuantity() const;
    double getCost() const;
    string getName() const;
    double getTotalCost() const;
};
// function prototypes
double totalCost(const vector<ShoppingItem>& items, ShoppingItem& cheapest, ShoppingItem& mostExpensive);
string toLower(string str);
void sortItems(vector<ShoppingItem>& items);

int main(int argc, char* argv[])
{
    vector<ShoppingItem> items;
    vector<string> shoppers;
    ShoppingItem cheapest, mostExpensive;
    ifstream fin;
    ofstream fout;
    istringstream sin;
    string line, temp, name, first, last, pause;
    fin.open(argv[1]);
    int qty;
    double cost, totaltotalC;

    if(argv[1] == NULL || argv[2] == NULL) {
        cout << "Requires two command line arguments.";
        return -1;
    }
    if(fin.fail()) {
        cout << "Unable to open input file.";
        return -1;
    }
    fout.open(argv[2]);
    if(fout.fail()) {
        cout << "Failed to open document";
        return -1;
    }

    while(getline(fin, line)) {
        
        sin.clear();
        if(line == "")
            getline(fin,line);
        sin.str(line);
        sin >> qty;
        if(qty == -1) {
            sin >> first >> last;
            sortItems(items);
            cheapest = items[0];
            mostExpensive = items[items.size()-1];
            totaltotalC = totalCost(items, cheapest, mostExpensive);
            for(int i=0; i<items.size(); i++) {
                temp = items[i].getName();
                temp[0] = toupper(temp[0]);
                fout << setprecision(2);
                fout << left << fixed << setw(16) << temp;
                fout << right << fixed << setw(3) << items[i].getQuantity() << " ";
                fout << right << fixed << setw(6) << items[i].getCost() << " ";
                fout << right << fixed << setw(7) << items[i].getTotalCost() << endl;
            }
            fout << endl;
            fout << "cheapest item = " << cheapest.getName() << endl;
            fout << "most expensive item = " << mostExpensive.getName() << endl;
            fout << "total cost = " << totaltotalC << endl;
            fout << "shopper = " << toLower(last) << " " << toLower(first) << endl << endl;
            items.clear();
            
        }
    else
    {
        sin >> cost >> name;
        items.push_back(ShoppingItem(qty, cost, name));
    }
    }

fout.close();
fin.close();
}
// constructors
ShoppingItem::ShoppingItem(int _qty, double _cost, const string& _name)
{
    quantity = _qty;
    cost = _cost;
    name = _name;
}
ShoppingItem::ShoppingItem()
{
}

// accessor functions
double ShoppingItem::getCost() const
{
    return cost;
}
string ShoppingItem::getName() const
{
    return name;
}
int ShoppingItem::getQuantity() const
{
    return quantity;
}
double ShoppingItem::getTotalCost() const
{
    return quantity * cost;
}

/* Purpose of totalCost: This function finds the total cost for a shopping cart and
 * returns it. Additionally, it outputs the lowest and highest costing items.
 * Arguments: vector of shopping items by constant reference, a shopping item
 * representing the cheapest item, and a shopping item representing the most expensive item.
 * Return type:
 */
double totalCost(const vector<ShoppingItem>& items, ShoppingItem& cheapest, ShoppingItem& mostExpensive)
{
    double totaltotal = 0;
    for(int i = 0; i < items.size(); i++) {
        totaltotal += items[i].getTotalCost();
    }
    return totaltotal;
}

void sortItems(vector<ShoppingItem>& items)
{
    bool sorted;
    ShoppingItem temp;
    do {
        sorted = true;
        for(int i = 1; i < items.size(); i++) {
            if(items[i - 1].getCost() > items[i].getCost()) {
                sorted = false;
                temp = items[i - 1];
                items[i - 1] = items[i];
                items[i] = temp;
            }
        }
    } while(!sorted);
}
/*Purpose of toLower: This function will convert any string into a lowercase string
 * by converting to a c-style string, converting each individual character to
 * lowercase, then converting it back to a string and returning it.
 * Arguments: c++ style string to be converted to lowercase.
 * Return type: lowercase C++ style string
 */
string toLower(string str)
{
    int i = 0;
    while(i < str.size()) {
        str[i] = tolower(str[i]);
        i++;
    }
    str[0] = toupper(str[0]);

    return str;
}
