#include <bits/stdc++.h>
using namespace std;
/*8.	Exceptions / Templates. Kirolos Usama is trying to learn how stacks work by building one. He needs your help to develop a template stack class with methods: push, pop, top, size and empty. An object of our stack class has a fixed size given as a parameter to the constructor and it does not expand. Define also the big 3 methods for it. When used in a program, an object of the stack class will throw exceptions in the following situations:
•	Throw a StackOverflowException if the application program tries to push data onto a stack that is already full
•	Throw a StackEmptyException if the application program tries to pop data off an empty stack
*/
template <class T>//with big 3 and exceptions
class Stack
{
private:
    T *arr;
    int top;
    int size;
public:
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
        top = -1;
    }
    ~Stack()
    {
        delete[] arr;
    }
    Stack(const Stack &other)
    {
        this->size = other.size;
        this->top = other.top;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            delete[] arr;
            this->size = other.size;
            this->top = other.top;
            arr = new T[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    void push(T data)
    {
        try{
            if (top == size - 1)
            {
                throw "StackOverflowException";
            }
            else
            {
                top++;
                arr[top] = data;
            }
        }
        catch(const char* msg){
            cout<<msg<<endl;
        }
    }
    void pop()
    {
        try{
            if (top == -1)
            {
                throw "StackEmptyException";
            }
            else
            {
                top--;
            }
        }
        catch(const char* msg){
            cout<<msg<<endl;
        }

    }
    T Top()
    {
        try{
            if (top == -1)
            {
                throw "StackEmptyException";
            }
            else
            {
                return arr[top];
            }
        }
        catch(const char* msg){
            cout<<msg<<endl;
        }
    }
    int Size()
    {
        return top + 1;
    }
    bool empty()
    {
        return top == -1;
    }
};

int main(){//test the stack class
    Stack<int> s(5);
    Stack<int> s2(7);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s2 = s;
    s2.push(7);
    for(int i=0;i<6;i++){
        cout<<s2.Top()<<endl;
        s2.pop();
    }
    return 0;
}
