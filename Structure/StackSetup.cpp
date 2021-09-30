#pragma once
#include<iostream>
using namespace std;

class Stack{
private:
    int* data;
    int Size;
    int n;
public:

    Stack(int capacity){
        data = new int[capacity];
        Size =0;
        n=capacity;
    }

    bool isEmpty(){return Size==0;}

    int getSize(){return Size;}

    void push(int item){
        data[Size++] = item;
    }

    void pop(){
        if(!isEmpty())Size--;
    }

    int getTop(){
        return data[Size-1];
    }
}
