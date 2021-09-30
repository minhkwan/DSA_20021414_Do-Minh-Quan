#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node* next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};
 
struct Queue {
    Node *front, *rear;
    int Size;
    Queue()
    {
        front = rear = NULL;
    }
    int getSize(){return Size;}
    bool isEmpty(){return rear == NULL;}

    void enQueue(int x)
    {
        Node* temp = new Node(x);
 
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        rear++;
    }
    void deQueue()
    {
        if (front == NULL)
        return;

        Node* temp = front;
        front = front->next;
 
         if (front == NULL)
            rear = NULL;

        rear--;
    }
};