#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int a[100];

    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        a[top + 1] = x;
        top++;
    }

    void pop()
    {
        int x = a[top - 1];
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

int main()
{
    Stack s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        if (s1 == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        if (s1 == "pop")
        {
            s.pop();
        }
    }
    s.Display();
}