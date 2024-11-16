#include "queue.h"
#include <iostream>
using namespace std;

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue is full!" << endl;
    } else {
        if(isEmptyQueue(Q)){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "Empty queue" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        Q.head++;
        if(Q.head > Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << "  : empty queue" << endl;
    } else {
        cout << Q.head << " - " << Q.tail << "    : ";
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << endl;
    }
}
