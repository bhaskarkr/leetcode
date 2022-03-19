class FreqStack {
public:
    unordered_map<int, stack<int>> freqStk;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(freq[val], maxFreq);
        freqStk[freq[val]].push(val);
    }
    
    int pop() {
        int ans = freqStk[maxFreq].top();
        freqStk[maxFreq].pop();
        freq[ans]--;
        if(!freqStk[maxFreq].size())
            maxFreq--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
