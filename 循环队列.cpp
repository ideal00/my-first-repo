class MyCircularQueue {
private:
    vector<int> queue;  // 动态数组存储队列元素（替代固定大小数组）
    int capacity;       // 队列最大容量（题目中的k）
    int front;          // 队首指针（指向队首元素）
    int rear;           // 队尾指针（指向队尾元素的下一个位置）
    int count;          // 当前队列元素个数（简化空/满判断）

public:
    // 构造器：仅保留题目要求的带参构造，设置队列长度为k
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);  // 初始化动态数组大小为k
        front = 0;        // 队首初始化为0
        rear = 0;         // 队尾初始化为0
        count = 0;        // 初始元素个数为0（空队列）
    }
    
    // 入队：成功返回true，失败（满）返回false
    bool enQueue(int value) {
        if (isFull()) return false;  // 队列满则插入失败
        queue[rear] = value;         // 存入新元素到队尾位置
        rear = (rear + 1) % capacity; // 队尾指针循环后移
        count++;                     // 元素个数+1
        return true;
    }
    
    // 出队：成功返回true，失败（空）返回false
    bool deQueue() {
        if (isEmpty()) return false; // 队列空则删除失败
        front = (front + 1) % capacity; // 队首指针循环后移
        count--;                       // 元素个数-1
        return true;
    }
    
    // 获取队首元素：空则返回-1
    int Front() {
        if (isEmpty()) return -1;
        return queue[front];
    }
    
    // 获取队尾元素：空则返回-1
    int Rear() {
        if (isEmpty()) return -1;
        // 队尾指针指向“下一个位置”，需回退一位（+capacity避免负数）
        return queue[(rear - 1 + capacity) % capacity];
    }
    
    // 判断队列是否为空
    bool isEmpty() {
        return count == 0; // 元素个数为0则空
    }
    
    // 判断队列是否已满
    bool isFull() {
        return count == capacity; // 元素个数等于容量则满
    }
};