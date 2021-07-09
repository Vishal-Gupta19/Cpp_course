/*
C++ 11 features
--------------------

Lambda Expressions

*/

#include <iostream>
using namespace std;

template<typename T>
void fun(T p) {
	p(); 
}

int main()
{
	// Lambda Expressions
	[]() {cout << "Hello" << endl; }();
	cout << "---------------" << endl;
	[](int x, int y) {cout << "Sum is " << x + y << endl; }(4, 5);
	cout << "---------------" << endl;

	cout << ([](int x, int y) {return x + y; }(4, 5)) << endl;
	cout << "---------------" << endl;

	int a = [](int x, int y)->int {return x + y; }(4, 5);
	cout << a << endl;
	cout << "---------------" << endl;

	a = 10;
	[a]() {cout << a << endl; }();
	cout << "---------------" << endl;

	auto f = [a]() {cout << a << endl; };
	f();
	a++;
	f(); // a will not be modified
	cout << "---------------" << endl;

	auto f2 = [&a]() {cout << a << endl; };
	f2();
	a++;
	f2(); // a will be modified
	cout << "---------------" << endl;

	fun(f2);
	a++;
	fun(f2);
}

/*
OUTPUT
----------------

Hello
---------------
Sum is 9
---------------
9
---------------
9
---------------
10
---------------
10
10
---------------
11
12
---------------
12
13

*/