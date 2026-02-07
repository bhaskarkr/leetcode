class MinStack {
public:
    vector<int> vec, minTillNow;
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        if(minTillNow.empty()) {
            minTillNow.push_back(val);
        } else {
            minTillNow.push_back(min(minTillNow.back(), val));
        }
    }
    
    void pop() {
        vec.pop_back();
        minTillNow.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return minTillNow.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);


 
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
public:
    stack<pair<int, int>> minStk;
    MinStack() {
        minStk.push({INT_MAX, INT_MAX});
    }
    
    void push(int val) {
        minStk.push({val, min(val, minStk.top().second)});
    }
    
    void pop() {
        minStk.pop();
    }
    
    int top() {
        return minStk.top().first;
    }
    
    int getMin() {
        return minStk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
