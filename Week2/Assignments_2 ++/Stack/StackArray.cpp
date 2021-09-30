#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int a[100];

    Stack()
    {
        top = 0;
    }

    bool isEmpty(){return top==0;}

    int getSize(){return top-1;}

    void push(int x)
    {
        a[top] = x;
        top++;
    }

    void pop()
    {
        top--;
    }

    void Display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << a[i] << " ";
        }
    }
};