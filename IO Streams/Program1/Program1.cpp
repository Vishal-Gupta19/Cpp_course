/*
I/O Stream
--------------
Serialization example
*/

#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
	string name;
	int roll;
	string branch;

	friend ofstream& operator<<(ofstream& ofs, Student& s);
	friend ifstream& operator>>(ifstream& ifs, Student& s);
};

ofstream& operator<<(ofstream& ofs, Student& s) {
	ofs << s.name << endl;
	ofs << s.roll << endl;
	ofs << s.branch << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Student& s) {
	ifs >> s.name;
	ifs >> s.roll;
	ifs >> s.branch;
	return ifs;
}

int main()
{
	Student s1;
	s1.name = "John";
	s1.roll = 10;
	s1.branch = "CS";

	ofstream ofs("Student.txt", ios::trunc);
	ofs << s1.name << endl;
	ofs << s1.roll << endl;
	ofs << s1.branch << endl;

	Student s2;
	s2.name = "Peter";
	s2.roll = 11;
	s2.branch = "CS";

	// Using Operator Overloading
	ofs << s2;
	ofs.close();

	// Reading from the file
	Student s11;
	ifstream ifs("Student.txt");
	ifs >> s11;
	cout << s11.name << endl;
	cout << s11.roll << endl;
	cout << s11.branch << endl;
	ifs.close();
}
