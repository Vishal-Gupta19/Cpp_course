/*
Scope Resolution Operator
----------------------------

In C++, scope resolution operator is ::. It is used for following purposes.

1) To access a global variable when there is a local variable with same name.

2) To define a function outside a class.

3) To access a class’s static variables.

4) In case of multiple Inheritance: If same variable name exists in two ancestor classes, we can use scope resolution operator to distinguish.

5) For namespace: If a class having the same name exists inside two namespace we can use the namespace name with the scope resolution operator to refer that class without any conflicts

6) Refer to a class inside another class: If a class exists inside another class we can use the nesting class to refer the nested class using the scope resolution operator

*/

#include <iostream>

using namespace std;

//-------------------------------------
// Global Variable
int a;
//-------------------------------------
class Rectangle {
private:
    int length;
    int breadth;

public:
    // Constructors
    Rectangle();
    Rectangle(int l, int b);
    Rectangle(Rectangle& rect);

    // Accessors
    int getLength();
    int getBreadth();

    // Mutators
    void setLength(int l);
    void setBreadth(int b);

    int area();
    int perimeter();

    // Inspector
    int isSquare();

    // Destructor
    ~Rectangle();
};
//-------------------------------------

class Test {
private:
    static int x;
public:
    static int y;

    // Local parameter x hides class member
    // x, but we can access it using ::
    void func(int x)
    {
        // We can access class's static variable
        // even if there is a local variable
        cout << "Value of static x is " << Test::x;

        cout << "\nValue of local x is " << x;
    }
};
// In C++, static members must be explicitly defined 
// like this
int Test::x = 1;
int Test::y = 2;
//-------------------------------------

class A
{
protected:
    int x;
public:
    A() { x = 10; }
};

class B
{
protected:
    int x;
public:
    B() { x = 20; }
};

class C : public A, public B {
public:
    void fun()
    {
        cout << "A's x is " << A::x << endl;
        cout << "B's x is " << B::x << endl << endl;
    }
};
//-------------------------------------
class outside
{
public:
    int x;
    class inside
    {
    public:
        int x;
        static int y;
        int foo();

    };
};
int outside::inside::y = 5;
//-------------------------------------

int main()
{
    // 1
    int a = 10; // Local x
    cout << "Value of global a is " << ::a;
    cout << "\nValue of local a is " << a << endl << endl;

    // 2
    cout << "Creating an object of Rectangle Class using Default constructor!\n";
    Rectangle r1;
    r1.setLength(10);
    r1.setBreadth(5);
    cout << "Area of Rectangle: " << r1.area() << " and Perimeter of Rectangle: " << r1.perimeter() << endl;
    cout << "Creating an object of Rectangle Class using Parameterised constructor!\n";
    Rectangle r2(20, 20);
    cout << "Area of Rectangle: " << r2.area() << " and Perimeter of Rectangle: " << r2.perimeter() << endl;
    cout << "Creating an object of Rectangle Class using Copy constructor!\n";
    Rectangle r3(r1);
    cout << "Area of Rectangle: " << r3.area() << " and Perimeter of Rectangle: " << r3.perimeter() << endl;
    if (r2.isSquare()) {
        cout << "It's a Square" << endl << endl;
    }

    // 3
    Test obj;
    int x = 3;
    obj.func(x);
    cout << "\nTest::y = " << Test::y << endl << endl;

    // 4
    C c;
    c.fun();

    // 6
    outside A;
    outside::inside B;
    A.x = 5;
    B.x = 6;
    cout << "x in outside: " << A.x << " and x in inside: " << B.x << " and y is: " << B.y << endl << endl;

    return 0;
}
//-------------------------------------

Rectangle::Rectangle() {
    length = 0;
    breadth = 0;
}
Rectangle::Rectangle(int l, int b) {
    setLength(l);
    setBreadth(b);
}
Rectangle::Rectangle(Rectangle& rect) {
    length = rect.length;
    breadth = rect.breadth;
}

int Rectangle::getLength() {
    return length;
}
int Rectangle::getBreadth() {
    return breadth;
}

void Rectangle::setLength(int l) {
    length = l;
}
void Rectangle::setBreadth(int b) {
    breadth = b;
}

int Rectangle::area() {
    return length * breadth;
}
int Rectangle::perimeter() {
    return 2 * (length * breadth);
}

int Rectangle::isSquare() {
    return length == breadth;
}

Rectangle::~Rectangle() {
    cout << "Rectangle Destroyed" << endl;
}
//-------------------------------------

/*
OUTPUT:
-----------
Value of global a is 0
Value of local a is 10

Creating an object of Rectangle Class using Default constructor!
Area of Rectangle: 50 and Perimeter of Rectangle: 100
Creating an object of Rectangle Class using Parameterised constructor!
Area of Rectangle: 400 and Perimeter of Rectangle: 800
Creating an object of Rectangle Class using Copy constructor!
Area of Rectangle: 50 and Perimeter of Rectangle: 100
It's a Square

Value of static x is 1
Value of local x is 3
Test::y = 2

A's x is 10
B's x is 20

x in outside: 5 and x in inside: 6 and y is: 5

Rectangle Destroyed
Rectangle Destroyed
Rectangle Destroyed

*/