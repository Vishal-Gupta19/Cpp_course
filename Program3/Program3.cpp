/*
CONSTRUCTOR
----------------
A constructor is a member function of a class which initializes objects of a class. 
In C++, Constructor is automatically called when object(instance of class) create. 
It is special member function of the class.

- Constructor has same name as the class itself
- Constructors don’t have return type
- A constructor is automatically called when an object is created.

Types:
(a) Default (Non-parameterized)
(b) Parameterized
(c) Copy

Default Constructors: Default constructor is the constructor which doesn’t take any argument. It has no parameters.
Even if we do not define any constructor explicitly, the compiler will automatically provide a default constructor implicitly.

Parameterized Constructors: To create a parameterized constructor, simply add parameters to it the way you would to any other function. 
When you define the constructor’s body, use the parameters to initialize the object. 
When an object is declared in a parameterized constructor, the initial values have to be passed as arguments to the constructor function.
The normal way of object declaration may not work. The constructors can be called explicitly or implicitly.
Uses of Parameterized constructor:
It is used to initialize the various data elements of different objects with different values when they are created.
It is used to overload constructors.

Copy Constructor: A copy constructor is a member function which initializes an object using another object of the same class.

*/

#include <iostream>

class Rectangle {
private:
    int length;
    int breadth;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    // Parameterized constructor
    Rectangle(int l, int b) {
        setLength(l);
        setBreadth(b);
    }
    // Copy constructor
    Rectangle(Rectangle& rect) {
        length = rect.length;
        breadth = rect.breadth;
    }

    int getLength() {
        return length;
    }
    void setLength(int l) {
        length = l;
    }
    int getBreadth() {
        return length;
    }
    void setBreadth(int b) {
        breadth = b;
    }
    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length * breadth);
    }
};

int main()
{
    std::cout << "Rectangle!\n";
    std::cout << "Creating an object of Rectangle Class using Default constructor!\n";
    Rectangle r1;
    r1.setLength(10);
    r1.setBreadth(5);
    std::cout << "Area of Rectangle: " << r1.area() << std::endl;
    std::cout << "Perimeter of Rectangle: " << r1.perimeter() << std::endl;
    std::cout << "Sizeof Rectangle object: " << sizeof(r1) << std::endl << std::endl;

    std::cout << "Creating an object of Rectangle Class using Parameterised constructor!\n";
    Rectangle r2(50, 20);
    std::cout << "Area of Rectangle: " << r2.area() << std::endl;
    std::cout << "Perimeter of Rectangle: " << r2.perimeter() << std::endl;
    std::cout << "Sizeof Rectangle object: " << sizeof(r2) << std::endl << std::endl;

    std::cout << "Creating an object of Rectangle Class using Copy constructor!\n";
    Rectangle r3(r1);
    std::cout << "Area of Rectangle: " << r3.area() << std::endl;
    std::cout << "Perimeter of Rectangle: " << r3.perimeter() << std::endl;
    std::cout << "Sizeof Rectangle object: " << sizeof(r3) << std::endl;

}

/*
OUTPUT:
-----------
Rectangle!
Creating an object of Rectangle Class using Default constructor!
Area of Rectangle : 50
Perimeter of Rectangle : 100
Sizeof Rectangle object : 8

Creating an object of Rectangle Class using Parameterised constructor!
Area of Rectangle : 1000
Perimeter of Rectangle : 2000
Sizeof Rectangle object : 8

Creating an object of Rectangle Class using Copy constructor!
Area of Rectangle : 50
Perimeter of Rectangle : 100
Sizeof Rectangle object : 8
*/