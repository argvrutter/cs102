class Student 
{
int score;
string name, address, major;
double gpa;
public:
Student(); //zero arg constructor
Student(String n);
Student(string n, string maj, double gradePtAvg)
: name(n), major(maj), gpa(gradePtAvg) {};   
};
