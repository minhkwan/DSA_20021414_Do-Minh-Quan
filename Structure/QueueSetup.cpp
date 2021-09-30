#pragma once
#include<iostream>
using namespace std;

class Queue{
private:
    int* data;
    int Size;
    int n;
public:
    Queue(){}

    Queue(int capacity){
        data = new int[capacity];
        Size =0;
        n=capacity;
    }

    bool isEmpty(){return Size==0;}

    int getSize(){return Size;}

    void push(int item){
        data[Size++]=item;
    }

     void pop(){
        if(!isEmpty()){
            for(int i=0;i<Size-1;i++){
                    data[i]=data[i+1];
                }
            Size--;

        }
    }
    int getFirst(){
        if(!isEmpty()){
            return data[0];
        }
        else return nullptr;
};

