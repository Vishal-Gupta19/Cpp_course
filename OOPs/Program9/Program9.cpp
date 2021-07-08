/*
Application of Runtime Polymorphism

A virtual function is a member function which is declared in the base class using the keyword virtual and is re-defined (Overriden) by the derived class.
The term Polymorphism means the ability to take many forms. It occurs if there is a hierarchy of classes which are all related to each other by inheritance.

Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing kind of derived class object.

*/
#include <iostream>
using namespace std;

class Car {
public: 
    virtual void start() {
        cout << "Car Started" << endl;
    }
};

class Tiago : public Car {
public:
    void start() {
        cout << "Tiago Started" << endl;
    }
};

class I20 : public Car {
public:
    void start() {
        cout << "I20 Started" << endl;
    }
};

int main()
{
    Car* p = new Tiago();
    p->start();
    p = new I20();
    p->start();
}

/*
OUTPUT:
-----------
Tiago Started
I20 Started

*/