#include <bits/stdc++.h>
using namespace std;

template <class T>
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
