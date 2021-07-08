/*
Applications of Constant Qualifier
*/

#include <iostream>
using namespace std;

class Demo {
public:
	int x = 10;
	int y = 20;

	void Display() const
	{
		// x++;			// Function declared const, so cannot modify variables
		cout << x << endl;
	}
};

// function using call by reference. By making the arguments as const, we can restrict the user to modify the variables
void fun(const int& a, int b) {
	cout << a << " " << b << endl;
	// a++;				// Cannot modify this variable
}

int main()
{
	const int x = 10;
	//	x++;			// Cannot modify this variable

	const int y = 10;
	const int* ptr = &y;
	// ++* ptr;			// Cannot modify this variable
	cout << *ptr << " " << y << endl;
	int z = 20;
	ptr = &z;

	int * const ptr2 = &z;
	int a = 5;
	// ptr2 = &a;		// Cannot modify this variable

	fun(5, 2);

}
