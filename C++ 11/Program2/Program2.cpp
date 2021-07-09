/*
C++ 11 features
---------------------

Smart pointers

*/

#include <iostream>
using namespace std;

class Rectangle {
    int length;
    int breadth;
public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    int area() {
        return length * breadth;
    }
};

int main()
{
    cout << "Using unique_ptr:" << endl << "--------------------" << endl;
    unique_ptr<Rectangle> ptr1(new Rectangle(10, 5));
    cout << ptr1->area() << endl;
    unique_ptr<Rectangle> ptr2;
    // ptr2 = ptr1; // ERROR
    // ptr2(ptr1); // ERROR, will not be able to create one more pointer, pointing to the same object
    ptr2 = move(ptr1); // This will remove ptr1 and the object will be pointed by ptr2
    cout << ptr2->area() << endl;
    try
    {
        if (ptr1)
            cout << ptr1->area() << endl;
        else
            throw 0;
    }
    catch (...) {
        cout << "ptr1 is not pointing to Rectangle class" << endl;
    }


    cout << endl << "Using shared_ptr:" << endl << "--------------------" << endl;
    shared_ptr<Rectangle> sptr1(new Rectangle(10, 5));
    cout << sptr1->area() << endl;
    shared_ptr<Rectangle> sptr2;
    sptr2 = sptr1; 
    cout << "Area using sptr2: " << sptr2->area() << endl;
    cout << "Area using sptr1: " << sptr1->area() << endl;
    cout << "Number of pointer pointed to Rectangle object: " << sptr2.use_count() << endl;

}

/*
OUTPUT
-------------------

Using unique_ptr:
--------------------
50
50
ptr1 is not pointing to Rectangle class

Using shared_ptr:
--------------------
50
Area using sptr2: 50
Area using sptr1: 50
Number of pointer pointed to Rectangle object: 2

*/