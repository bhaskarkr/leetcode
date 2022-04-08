class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> PQ;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int num : nums) {
            PQ.push(num);
            if(PQ.size() > k)
                PQ.pop();
        }
    }
    
    int add(int val) {
        PQ.push(val);
        if(PQ.size() > K)
                PQ.pop();
        return PQ.top();
    }
};
