#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int _data)
    {
        data = _data;
    }
};

struct SinglyLinkedListNode
{
    Node *head;
    SinglyLinkedListNode()
    {
        head = NULL;
    }

    void insert(int p, int x)
    {
        if (p == 0)
        {
            Node *newNode = new Node(x);
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            Node *nextNode = head->next;
            p--;
            while (p > 0)
            {
                ptr = ptr->next;
                nextNode = nextNode->next;
                p--;
            }
            Node *newNode = new Node(x);
            ptr->next = newNode;
            newNode->next = nextNode;
        }
    }

    void Delete(int p)
    {
        Node *ptr = head;
        Node *nextNode = head->next->next;
        if(p == 0){
            ptr = ptr->next;
            head = ptr;
        }
        else{
        while (p > 1)
        {
            ptr = ptr->next;
            nextNode = nextNode->next;
            p--;
        }
        ptr->next = nextNode;    
        }
}};

void printOut(SinglyLinkedListNode Li)
{
    Node *ptr = Li.head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    SinglyLinkedListNode Li;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int p, x;
            cin >> p;
            cin >> x;
            Li.insert(p, x);
        }
        else if (s == "delete")
        {
            int p;
            cin >> p;
            Li.Delete(p);
        }
    }
    printOut(Li);
}