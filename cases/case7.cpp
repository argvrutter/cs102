/* AUTHOR: AIDAN RUTTER
 * DATE: 4/20/17
 * ASSIGNMENT: CASE 7: PICTURE THIS
 *
 * PURPOSE: READ AN IMAGE IN A PPM FILE FORMAT, MODIFY IT, AND OUTPUT A NEW PICTURE.
 * THIS WILL GIVE STUDENTS PRACTICE WITH FILE I/O, 2D VECTORS, CLASSES, ETC.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;
/*
 *
 */
struct Pixel {
    int red, green, blue;
    Pixel(int r, int g, int b)
        : red(r)
        , green(g)
        , blue(b)
    {
    }
    Pixel()
        : red(0)
        , green(0)
        , blue(0)
    {
    }
};
/*
 *
 *
 */
class Picture
{
    vector<vector<Pixel> > picture_data;
    int numRows, numCols, colorRange;

public:
    Picture();
    bool readPic(ifstream& fin);
    bool writePic(ofstream& fout);
    bool flipX();
    bool flipY();
    bool invertIntensity();
};

int main(int argc, char* argv[])
{
    // variables
    ifstream fin;
    ofstream fout;
    istringstream sin;
    string line;
    Picture pic;

    // argument checks
    if(argc == NULL || argv[1] == NULL || argv[2] == NULL) {
        cout << "Usage: inputfile outputfile [XYI]";
        return -1;
    }
    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "Unable to read PPM file " << argv[1];
        return -1;
    }
    fout.open(argv[2]);
    if(fout.fail()) {
        cout << "Unable to write PPM file " << argv[2];
        return -1;
    }
    do {
        getline(fin, line);
    } while(line == "");
    if(line != "P3") {
        cout << "Error: Unable to read PPM file " << argv[1];
        return -1;
    }
    if(!pic.readPic(fin))
    {
        cout << "Error: tried to output an uninitialized PPM picture";
        return -1;
    }
    if(argv[3] != NULL) {
        sin.clear();
        sin.str(argv[3]);
        sin >> line;
        switch(line[0]) {
        case('Y'): {
            pic.flipY();
            break;
        }
        case('X'): {
            pic.flipX();
            break;
        }
        case('I'): {
            pic.invertIntensity();
            break;
        }
        default: {
            cout << "Error: " << line[0] << " is an invalid command. Use either X, Y, or I";
            return -1;
        }
        }
    }
    if(!pic.writePic(fout)){
        cout << "Error: tried to output an uninitialized PPM picture";
        return -1;
    }

    fin.close();
    fout.close();
}
/* Purpose of fillPic:
 * Arguments: the inputfile, which will contain the ppm data.
 * Return type: bool representing successful execution, full read.
 */
Picture::Picture()
{
}
bool Picture::readPic(ifstream& fin)
{
    int r, g, b;
    vector<Pixel> row;
    istringstream sin;
    string line;

    sin.clear();
    do {
        getline(fin, line);
    } while(line == "");
    sin.str(line);
    sin >> numCols >> numRows;
     do {
        getline(fin, line);
    } while(line == "");
    sin.clear();
    sin.str(line);
    if(numCols == 0 || numRows == 0) {
        return false;
    }
    sin >> colorRange;
    for(int i = 0; i < numRows; i++) { // rows
        row.clear();
        for(int j = 0; j < numCols; j++) // columns
        {
           if(!sin.eof()){//not sure if this is allowed but couldnt think of a diff way
            sin.clear();
            do {
                getline(fin, line);
            } while(line == "");
           sin.str(line);}
            sin >> r >> g >> b;
            row.push_back(Pixel(r, g, b));
        }
        picture_data.push_back(row);
    }
    if(numRows == picture_data.size() && numCols == picture_data[0].size()) {
        return true;
    } else {
        return false;
    }
}
/* Purpose: Takes the 2D vector of pixels and outputs it in a PPM format to an output file.
 * Arguments: The output filestream by reference.
 * Return type: a bool representing a successful or unsucessful write.
 */
bool Picture::writePic(ofstream& fout)
{
    if(numRows == 0) {
        cout << "Error: Unable to write uninitialized PPM picture.";
        return false;
    }
    // cout << endl << "amount of rows: " << picture_data.size() << endl;
    fout << "P3" << endl;
    fout << numCols << " " << numRows << endl;
    fout << colorRange << endl;
    for(int i = 0; i < numRows; i++) // rows
    {
        for(int j = 0; j < numCols; j++) // columns
        {
            fout << picture_data[i][j].red << " " << picture_data[i][j].green << " " << picture_data[i][j].blue << endl;
        }
    }
    return true;
}
/* Purpose of flipY: Reflect the vector across the y axis(ie left is right)
 * Arguments: None
 * Return type: Bool representing success or failure.
 */
bool Picture::flipY()
{
    vector<Pixel> temp;
    if(numRows == 0)
        return false;
    for(int i=0; i<numRows; i++)//rows
    {
        for(int j=numCols-1;j>=0; j--)
        {
            temp.push_back(picture_data[i][j]);
        }
        picture_data[i] = temp;
        temp.clear();
    }
    return true;
}
/* Purpose of flipX Reflect the vector across he x axis(ie from up to down)
 * Arguments: None
 * Return type: Bool representing success or failure.
 */
bool Picture::flipX()
{
    vector<vector<Pixel>> temp;
    if(numRows == 0)
        return false;
    int j = 0;
    for(int i = numRows - 1; i >= 0; i--) // rows
    {
        temp.push_back(picture_data[i]);
    }
    picture_data = temp;
    return true;
}
/*Purpose: Inverts the intensity of each RGB value in the vector.
 * Arguments: None
 * Return type: Bool indicating success or failure.
 */
bool Picture::invertIntensity()
{
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            picture_data[i][j].red = colorRange - picture_data[i][j].red;
            picture_data[i][j].green = colorRange - picture_data[i][j].green;
            picture_data[i][j].blue = colorRange - picture_data[i][j].blue;
        }
    }
    return true;
}
