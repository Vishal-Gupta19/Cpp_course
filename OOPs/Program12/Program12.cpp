/*
Static Members
------------------

Static data member are class members that are declared using static keyword

A static member has certain special characteristics. These are:

> Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created.
> It is initialized to zero when the first object of its class is created. No other initialization is permitted
> It is visible only within the class, but its lifetime is the entire program.

*/

#include <iostream>
using namespace std;

class Student {
public:
	int roll;
	string name;
	static int addNo;

	Student(string n) {
		addNo++;
		roll = addNo;
		name = n;
	}

	void display() {
		cout << "Name " << name << endl << "Roll " << roll << endl;
	}
};

int Student::addNo = 0;
 
int main()
{
	Student s1("John");
	Student s2("Peter");
	Student s3("Taylor");
	Student s4("A");
	Student s5("B");
	Student s6("C");

	s1.display();
	s2.display();
	s3.display();

	cout << "Number of Admissions " << Student::addNo << endl;
}

/*
OUTPUT
-----------------
Name John
Roll 1
Name Peter
Roll 2
Name Taylor
Roll 3
Number of Admissions 6

*/