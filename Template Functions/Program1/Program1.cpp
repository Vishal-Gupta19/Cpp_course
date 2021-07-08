/*
Application of Template functions and classes
---------------------------
Template in C++ is a feature. We write code once and use it for any data type including user defined data types.

How does template specialization work?
When we write any template based function or class, compiler creates a copy of that function/class whenever compiler sees that being used for a new data type or new set of data types(in case of multiple template arguments).
If a specialized version is present, compiler first checks with the specialized version and then the main template. Compiler first checks with the most specialized version by matching the passed parameter with the data type(s) specified in a specialized version.

*/

#include <iostream>
using namespace std;

template<class T>
class Stack {
private:
    T* stk;
    int top;
    int size;
public:
    Stack(int sz) {
        size = sz;
        top = -1;
        stk = new T[size];
    }
    void push(T x);
    T pop();
};

template<class T>
void Stack<T>::push(T x) {
    if (top == size - 1)
        cout << "Stack is Full";
    else {
        top++;
        stk[top] = x;
    }
}

template<class T>
T Stack<T>::pop() {
    T x = 0;
    if (top == -1)
        cout << "Stack is empty" << endl;
    else {
        x = stk[top];
        top--;
    }
    return x;
}

int main()
{
    Stack<int> s(10);
    s.push(10);
    s.push(23);
    s.push(33);

    Stack<float> f(10);
    f.push(1.0f);
    f.push(2.3f);
    f.push(3.3f);
}
