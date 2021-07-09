/*
STL
----
The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a prerequisite for working with STL.
STL has four components:
> Algorithms
> Containers
> Functions
> Iterators

Reference: https://www.geeksforgeeks.org/the-c-standard-template-library-stl/

*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <map>

using namespace std;

int main()
{
	cout << "Using vectors:" << endl << "--------------------------" << endl;
	vector<int> v = { 2, 4, 6, 8, 10 };
	v.push_back(20);
	v.push_back(30);
	vector<int>::iterator itr;
	cout << "Using for each loop" << endl;
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl << "Using iterator" << endl;
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl << endl;


	cout << "Using linked lists:" << endl << "--------------------------" << endl;
	list<int> v2 = { 2, 4, 6, 8, 10 };
	v2.push_back(20);
	v2.push_back(30);
	list<int>::iterator itr2;
	cout << "Using for each loop" << endl;
	for (int x : v2) {
		cout << x << " ";
	}
	cout << endl << "Using iterator" << endl;
	for (itr2 = v2.begin(); itr2 != v2.end(); itr2++) {
		cout << *itr2 << " ";
	}
	cout << endl << endl;


	cout << "Using forward linked lists:" << endl << "--------------------------" << endl;
	list<int> v3 = { 2, 4, 6, 8, 10 };
	v3.push_front(20);
	v3.push_front(30);
	list<int>::iterator itr3;
	cout << "Using for each loop" << endl;
	for (int x : v3) {
		cout << x << " ";
	}
	cout << endl << "Using iterator" << endl;
	for (itr3 = v3.begin(); itr3 != v3.end(); itr3++) {
		cout << *itr3 << " ";
	}
	cout << endl << endl;


	cout << "Using set:" << endl << "--------------------------" << endl;
	set<int> v4 = { 2, 4, 6, 8, 10 };
	v4.insert(20);
	v4.insert(30);
	set<int>::iterator itr4;
	cout << "Using for each loop" << endl;
	for (int x : v4) {
		cout << x << " ";
	}
	cout << endl << "Using iterator" << endl;
	for (itr4 = v4.begin(); itr4 != v4.end(); itr4++) {
		cout << *itr4 << " ";
	}
	cout << endl << endl;


	cout << "Using map:" << endl << "--------------------------" << endl;
	map<int, string> m;
	m.insert(pair<int, string>(1, "John"));
	m.insert(pair<int, string>(2, "Peter"));
	m.insert(pair<int, string>(3, "Taylor"));
	m.insert(pair<int, string>(4, "Dom"));
	map<int, string>::iterator itr5;
	for (itr5 = m.begin(); itr5 != m.end(); itr5++) {
		cout << itr5->first << " " << itr5->second << endl;
	}
	map<int, string>::iterator itr6;
	itr6 = m.find(2);
	cout << "Value found is: " << itr6->first << " " << itr6->second << endl;

}

/*
OUTPUT
-----------
Using for each loop
2 4 6 8 10 20 30
Using iterator
2 4 6 8 10 20 30

Using forward linked lists:
--------------------------
Using for each loop
30 20 2 4 6 8 10
Using iterator
30 20 2 4 6 8 10

Using set:
--------------------------
Using for each loop
2 4 6 8 10 20 30
Using iterator
2 4 6 8 10 20 30

Using map:
--------------------------
1 John
2 Peter
3 Taylor
4 Dom
Value found is: 2 Peter

*/