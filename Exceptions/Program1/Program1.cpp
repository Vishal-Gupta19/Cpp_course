/*
Exceptions
--------------
Exceptions are run-time anomalies or abnormal conditions that a program encounters during its execution. 

There are two types of exceptions: a)Synchronous, b)Asynchronous

C++ provides following specialized keywords for this purpose:
> try: represents a block of code that can throw an exception.
> catch: represents a block of code that is executed when a particular exception is thrown.
> throw: Used to throw an exception. Also used to list the exceptions that a function throws, but doesn’t handle itself.
*/

#include <iostream>
using namespace std;

int division(int a, int b) {
    if (b == 0) {
        throw 1;
    }
    return a / b;
}

int main()
{

    int x = 10, y = 0, z;

    try {
        z = division(x, y);
        cout << z << endl;
    }
    catch (int e) {
        cout << "Division by zero " << e << endl;
    }
}
