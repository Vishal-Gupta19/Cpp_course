/*
Adding a class and member variables and functions

All the class members are declared under public specifier and will be available to everyone
*/
#include <iostream>

class Rectangle {
public:
    int length;
    int breadth;

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
    std::cout << "Creating an object of Rectangle Class!\n";
    Rectangle r1;

    r1.length = 10;
    r1.breadth = 5;

    std::cout << "Area of Rectangle: " << r1.area() << std::endl;
    std::cout << "Perimeter of Rectangle: " << r1.perimeter() << std::endl;
    std::cout << "Sizeof Rectangle object: " << sizeof(r1) << std::endl;

    return 0;
}


/*
OUTPUT:
-----------
Rectangle!
Creating an object of Rectangle Class!
Area of Rectangle: 50
Perimeter of Rectangle: 100
Sizeof Rectangle object: 8

*/