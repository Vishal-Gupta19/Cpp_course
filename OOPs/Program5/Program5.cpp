/*
Operator Overloading
-----------------------

In C++, we can make operators to work for user defined classes. 
This means C++ has the ability to provide the operators with a special meaning for a data type,
this ability is known as operator overloading.

Important points about operator overloading
1) For operator overloading to work, at least one of the operands must be a user defined class object.

2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. 
The default assignment operator does assign all members of right side to the left side and works fine most of the cases (this behavior is same as copy constructor).

3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type.
*/

#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------

class Complex1 {
public:
    int real;
    int img;
    Complex1 add(Complex1 c) {
        Complex1 temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};

class Complex2 {
public:
    int real;
    int img;
    Complex2 operator+(Complex2 c) {
        Complex2 temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};

class Complex3 {
private:
    int real;
    int img;
public:
    Complex3(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    friend Complex3 operator+(Complex3 c1, Complex3 c2);

    /*
    void display() {
        cout << real << " + i" << img << endl;
    }
    */
    // Insertion operator
    friend ostream& operator<<(ostream& out, Complex3& c);
};

Complex3 operator+(Complex3 c1, Complex3 c2) {
    Complex3 temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

ostream& operator<<(ostream& out, Complex3 &c) {
    out << c.real << " + i" << c.img;
    return out;
}

// ---------------------------------------------------------------------------------

class Test
{
public:
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }

    Test& operator = (const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

// ---------------------------------------------------------------------------------

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
    {}

    // magnitude : usual function style
    double mag()
    {
        return getMag();
    }

    // magnitude : conversion operator
    operator double()
    {
        return getMag();
    }

private:
    // class helper to get magnitude
    double getMag()
    {
        return sqrt(real * real + imag * imag);
    }
};

// ---------------------------------------------------------------------------------

int main()
{
    Complex1 c1, c2, c3;
    c1.real = 5; c1.img = 3;
    c2.real = 10; c2.img = 5;
    c3 = c1.add(c2);
    cout << c3.real << " + i" << c3.img << endl;
    
    
    Complex2 c4, c5, c6;
    c4.real = 5; c4.img = 3;
    c5.real = 10; c5.img = 5;
    c6 = c4 + c5;
    cout << c6.real << " + i" << c6.img << endl;


    Complex3 c7(5, 3), c8(10, 5), c9;
    c9 = c7 + c8;
    // OR c9 = operator+(c7, c8)
    // c9.display();
    cout << c9 << endl;
    // OR operator<<(cout, c);


    Test t1, t2;
    t2 = t1;
    Test t3 = t1;
    /*
    Copy constructor is called when a new object is created from an existing object, as a copy of the existing object. 
    And assignment operator is called when an already initialized object is assigned a new value from another existing object.
    t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
    Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"
    */


    // a Complex object
    Complex com(3.0, 4.0);
    // print magnitude
    cout << com.mag() << endl;
    // same can be done like this
    cout << com << endl;

    return 0;
}

/*
OUTPUT
--------------------
15 + i8
15 + i8
15 + i8
Assignment operator called
Copy constructor called
5
5

*/