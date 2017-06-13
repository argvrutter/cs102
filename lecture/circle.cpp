/*
 * Making a class: lecture 4/4/17
 */ 
#include <string>
class Circle {
    double radius;// member variable
public:// public is usable outside function
    void setRadius(double r);//funct definitions
    double getRadius();
    double getArea();
    double getCirc();
private:
    double gpa;
};
void Circle::setRadius(double r){//double colon to denote the class; function definitions
    radius = r;
};
double Circle::getRadius(){
    return radius;
};
double Circle::getArea(){
    // etc
};
#include <iostream>

using namespace std;
int main(){
    
    Circle c1,c2,c3;
    double myR;
    cout << "radius 1 and 2";
    cin >> myR;
    c1.setRadius(myR);
    cin >> myR;
    c2.setRadius(myR);
    cout << c1.getRadius() << c1.getArea() << endl;
    cout << c2.getRadius() << c2.getArea() << endl;
    c3=c2;
}