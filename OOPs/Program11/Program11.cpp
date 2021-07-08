/*
Friend Class
-----------------
A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example, a LinkedList class may be allowed to access private members of Node.

Like friend class, a friend function can be given a special grant to access private and protected members. A friend function can be:
a) A member of another class
b) A global function

Following are some important points about friend functions and classes:
1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited
4) The concept of friends is not there in Java.
*/

#include <iostream>
using namespace std;

class B;

class A {
private:
    int a;

public:
    A() { a = 0; }
    friend class B; // Friend Class
    void showB(B&);

};

class B {
private:
    int b;

public:
    B() { b = 0; }

    friend void A::showB(B& x); // Friend function

    void showA(A& x)
    {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a = " << x.a << endl;
    }
};

void A::showB(B& x)
{
    // Since showB() is friend of B, it can
    // access private members of B
    std::cout << "B::b = " << x.b << endl;
}

int main()
{
    A a;
    B b;
    b.showA(a);

    a.showB(b);
    return 0;
}

/*
OUTPUT:
-----------

A::a = 0
B::b = 0

*/