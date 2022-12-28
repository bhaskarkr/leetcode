class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> PQ(piles.begin(), piles.end());
        int ans = accumulate(piles.begin(), piles.end(), 0);
        while(k--) {
            int maxEle = PQ.top();
            PQ.pop();
            ans -= floor(maxEle/2); 
            PQ.push(maxEle - floor(maxEle/2));
        }
        return ans;
    }
};
