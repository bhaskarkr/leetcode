class MyCircularQueue {
private:
    vector<int> CQ;
    int currSize = 0, head = 0, tail = 0, maxSize = 0;
public:
    MyCircularQueue(int k) {
        maxSize = k;
        CQ.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(isEmpty()) {
            head = 0;
            tail = -1;
        }
        tail++;
        tail %= maxSize;
        currSize++;
        CQ[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        head++;
        head %= maxSize;
        currSize--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : CQ[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : CQ[tail];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
