class MedianFinder {
public:
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;
    int size;
    MedianFinder() {   
        size = 0;
    }
    
    void addNum(int num) {
         if(L.empty()) {
             L.push(num);
         } 
         else if(size%2) {
             int leftTop = L.top();
             if(leftTop < num)
                 R.push(num);
             else {
                 L.pop();
                 L.push(num);
                 R.push(leftTop);
             }
         } else {
            int rightTop = R.top();
             if(rightTop > num)
                 L.push(num);
             else {
                 R.pop();
                 R.push(num);
                 L.push(rightTop);
             }
         }
         size++;   
    }
    
    double findMedian() {
        if(size%2)
            return L.top();
        
        return (L.top() + R.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinder {
public:
    int size = 0;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(size%2 == 0) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
        size++;
    }
    
    double findMedian() {
        if(size%2 == 0)
            return (left.top() + right.top()) / 2.0;
        return (left.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
