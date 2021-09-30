#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    struct Node *top;
    int Size;

    int getSize(){return Size;}

    bool isEmpty(){return top == NULL;}

    void push(int data)
    {

        Node *temp = new Node();

        temp->data = data;

        temp->next = top;

        top = temp;
        Size++;
    }

    void pop()
    {
        struct Node *temp;

        if (top == NULL)
        {
            return;
        }
        else
        {

            temp = top;

            top = top->next;

            temp->next = NULL;
        }
        Size--;
    }
};