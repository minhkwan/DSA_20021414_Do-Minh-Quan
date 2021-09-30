#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int _data)
    {
        data = _data;
        next = NULL;
        prev = NULL;
    }
};

Node *head, *tail;

void InsertAtHead(int x)
{
    Node *newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x)
{
    Node *newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int count_triplets()
{
    Node *ptr = head->next;
    int count = 0;
    while (ptr->next != NULL)
    {
        if (ptr->data + ptr->prev->data + ptr->next->data == 0)
        {
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (i == 0)
        {
            InsertAtHead(input);
        }
        else
        {
            InsertAtTail(input);
        }
    }
    cout << count_triplets();
}