#include <bits/stdc++.h>
class Queue {
    int *arr;
    int qfront;
    int rear;

   public:
    Queue() {
        arr = new int[10000];
        qfront = -1;
        rear = -1;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (qfront == rear) return true;
        return false;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        qfront++;
        arr[qfront] = data;
        // Implement the enqueue() function
    }

    int dequeue() {
        if (qfront == rear) return -1;
        rear++;
        return arr[rear];
        // Implement the dequeue() function
    }

    int front() {
        if (qfront == rear) return -1;
        return arr[rear + 1];
        // Implement the front() function
    }
};