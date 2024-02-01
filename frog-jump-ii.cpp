class Solution {
public:
    int maxJump(vector<int>& stones) {
        int odd = 0, even = 0, n = stones.size();
        for(int i = 1; i < n; i ++) {
            if(i <= 2) {
                if(i%2)
                    odd = max(odd, stones[i] - stones[0]);
                else
                    even = max(even, stones[i] - stones[0]);
            } else {
                if(i%2)
                    odd = max(odd, stones[i] - stones[i - 2]);
                else
                    even = max(even, stones[i] - stones[i - 2]);
            }
      }
        return max(odd, even);
    }
};
