class MyCircularQueue {

private:
    int size;
    int a[1000];
    int front;
    int rear;

public:

    MyCircularQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }
    MyCircularQueue(int k) {
        size = k;
       
        front = -1;
        rear = -1;

    }
    
    bool enQueue(int value) {
        
        if(front == (rear + 1) % size) return false; // 队满
        a[(rear + 1) % size] = value; 
        rear = (rear + 1) % size;
        return true; 
    }
    
    bool deQueue() {
        if(front == rear) return false; // 队空
        front = (front + 1) % size;
        a[front] = 0; 
        return true;
    }
    
    int Front() {
        int val = a[(front + 1) % size];
        return val;
    }
    
    int Rear() {
        int val = a[rear];
        return val;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == (rear + 1) % size;
    }
};