#include <iostream>
using namespace std;

struct Queue{
    int front, rear, capacity;
    int* queue;

    Queue(int _capacity) {
        front = rear = 0;
        capacity = _capacity;
        queue = new int;
    }
    
    void enqueue(int x){
        if(capacity == rear){
            return;
        }

        else{
            queue[rear] = x;
            rear++;
        }
        return;
    }

    void dequeue(){
        if(front == rear){
            return;
        }
        else{
            for(int i = 0; i< rear-1; i++){
                queue[i] = queue[i+1];
            }
            rear--;
        }
    }

void Display(){
    for(int i = front; i<rear; i++){
        cout << queue[i] << " ";
    }
}
};

int main(){
    int n;
    cin >> n;
    Queue q(n);
    for(int i = 0; i<n; i++){
        int x;
        string s;
        cin >> s;
        if(s == "enqueue"){
            cin >> x;
            q.enqueue(x);
        }
        else if(s == "dequeue"){
            q.dequeue();
        }
    }
    q.Display();

}