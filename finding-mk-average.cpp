class MKAverage {
public:
    long M, K, middleSum = 0;
    queue<int> q;
    multiset<int> lower, middle, upper;
    MKAverage(int m, int k) {
        M = m;
        K = k;
    }
    
    void addElement(int num) {
        q.push(num);

        if(lower.size() < K) {
            lower.insert(num);
        } else {
            if(upper.size() < K) {
                if(num < *lower.rbegin()) {
                    lower.insert(num);
                    upper.insert(*lower.rbegin());
                    lower.erase(prev(lower.end()));
                } else {
                    upper.insert(num);
                }
            } else {
                if(num < *lower.rbegin()) {
                    lower.insert(num);
                    middle.insert(*lower.rbegin());
                    middleSum += *lower.rbegin();
                    lower.erase(prev(lower.end()));
                } else if(num > *upper.begin()) {
                    upper.insert(num);
                    middle.insert(*upper.begin());
                    middleSum += *upper.begin();
                    upper.erase(upper.begin());
                } else {
                    middle.insert(num);
                    middleSum += num;
                }


                if(q.size() > M) {
                    int poppedVal = q.front();
                    q.pop();
                    if(middle.find(poppedVal) != middle.end()) {
                        middle.erase(middle.find(poppedVal));
                        middleSum -= poppedVal;
                    } else if(lower.find(poppedVal) != lower.end()) {
                        lower.erase(lower.find(poppedVal));
                        lower.insert(*middle.begin());
                        middleSum -= *middle.begin();
                        middle.erase(middle.begin());
                    } else {
                        upper.erase(upper.find(poppedVal));
                        upper.insert(*middle.rbegin());
                        middleSum -= *middle.rbegin();
                        middle.erase(prev(middle.end()));
                    }
                }
            }
        }
    }
    
    int calculateMKAverage() {
        int count = lower.size() + middle.size() + upper.size();
        if(count < M)
            return -1;
        return middleSum / (count - 2*K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
