/*
Inheritance
------------------

The capability of a class to derive properties and characteristics from another class is called Inheritance. 
Inheritance is one of the most important feature of Object Oriented Programming.
Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
Super Class:The class whose properties are inherited by sub class is called Base Class or Super class.

 Modes of Inheritance

Public mode: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
Protected mode: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.
Private mode: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class.

*/
#include <iostream>

using namespace std;
//-------------------------------------
class Rectangle {
private:
    int length;
    int breadth;

public:
    // Constructors
    Rectangle(int l=0, int b=0);

    // Accessors
    int getLength();
    int getBreadth();

    // Mutators
    void setLength(int l);
    void setBreadth(int b);

    // Destructor
    ~Rectangle();
};
//-------------------------------------

class Cuboid : public Rectangle {
private:
    int height;
public:
    Cuboid(int h) {
        height = h;
        cout << "Cuboid Created" << endl;
    }

    int getHeight() { return height; }
    void setHeight(int h) { height = h; }
    int volume() {
        return getLength() * getBreadth() * height;

    }

    ~Cuboid() {
        cout << "Cuboid Destroyed" << endl;
    }
};

int main()
{
    Cuboid c(5);
    c.setLength(10);
    c.setBreadth(7);
    cout << "Volume of Cuboid is " << c.volume() << endl;
}


//-------------------------------------

Rectangle::Rectangle(int l, int b) {
    setLength(l);
    setBreadth(b);
    cout << "Rectangle Created" << endl;
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

Rectangle::~Rectangle() {
    cout << "Rectangle Destroyed" << endl;
}

/*
OUTPUT:
-----------------
Rectangle Created
Cuboid Created
Volume of Cuboid is 350
Cuboid Destroyed
Rectangle Destroyed

*/