/*
Abstract Class
------------------

1) A class is abstract if it has at least one pure virtual function.
2) We can have pointers and references of abstract class type.
*3) If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
4) An abstract class can have constructors.


An interface does not have implementation of any of its methods, it can be considered as a collection of method declarations. In C++, an interface can be simulated by making all methods as pure virtual. In Java, there is a separate keyword for interface.

************************
Base Class with
> All concrete functions --> Reusability  (Concrete Class)
> Some concrete and some pure virtual functions --> Reusability + Polymorphism (Abstract Class)
> All pure virtual functions --> Polymorphism (Abstract Class)

************************

*/

#include <iostream>
using namespace std;

class Car {
public:
    virtual void start() = 0;       // Pure Virtual Function
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