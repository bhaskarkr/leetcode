class Solution {
public:
    vector<int> presum;
    Solution(vector<int>& w) {
        presum.assign(w.begin(), w.end());
        for(int i = 1; i < w.size(); i++)
            presum[i] += presum[i-1];
    }
    
    int pickIndex() {
        int ran = (rand() * 1.0 / RAND_MAX) * presum.back();
        return upper_bound(presum.begin(), presum.end(), ran) - presum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
