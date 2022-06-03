class MovingAverage {
public:
    queue<int> Q;
    double sum;
    int limit;
    MovingAverage(int size) {
        limit = size;
        sum = 0;
    }
    
    double next(int val) {
        Q.push(val);
        sum += val;
        if(Q.size() > limit) {
            sum -= Q.front();
            Q.pop();
            return sum/limit;
        }
        return sum/Q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
