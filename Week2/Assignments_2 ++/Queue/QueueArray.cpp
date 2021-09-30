struct Queue{
    int front, rear, capacity;
    int* queue;

    Queue(int _capacity) {
        front = rear = 0;
        capacity = _capacity;
        queue = new int;
    }

    bool isEmpty(){return rear==0;}

    int getSize(){return rear;}

    void enqueue(int x){
        if(capacity == rear){
            return;
        }

        else{
            queue[rear++] = x;
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
};