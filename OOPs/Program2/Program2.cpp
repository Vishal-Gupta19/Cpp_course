/*
Adding a class and member variables and functions
The data members are available under private section and functions are available under public

 Private: The class members declared as private can be accessed only by the member functions inside the class. 
 They are not allowed to be accessed directly by any object or function outside the class. 
 Only the member functions or the friend functions are allowed to access the private data members of a class.

 Public: All the class members declared under the public specifier will be available to everyone. 
 The data members and member functions declared as public can be accessed by other classes and functions too. 
 The public members of a class can be accessed from anywhere in the program using the direct member access 
 operator (.) with the object of that class.

 Protected: Protected access modifier is similar to private access modifier in the sense that it can’t be accessed 
 outside of it’s class unless with the help of friend class, the difference is that the class members declared as 
 Protected can be accessed by any subclass(derived class) of that class as well. 
 */
#include <iostream>

class Rectangle {
private:
    int length;
    int breadth;

public:
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

class Parent {
protected:
    int id;
};

class Child : public Parent {
public:
    void setId(int num) {
        id = num;
    }

    void displayId() {
        std::cout << "id is " << id << std::endl;
    }
};

int main()
{
    std::cout << "Rectangle!\n";
    std::cout << "Creating an object of Rectangle Class!\n";
    Rectangle r1;

    r1.setLength(10);
    r1.setBreadth(5);

    std::cout << "Area of Rectangle: " << r1.area() << std::endl;
    std::cout << "Perimeter of Rectangle: " << r1.perimeter() << std::endl;
    std::cout << "Sizeof Rectangle object: " << sizeof(r1) << std::endl;

    Child obj1;
    obj1.setId(10);
    obj1.displayId();

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
id is 10
*/