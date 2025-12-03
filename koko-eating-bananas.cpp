class Solution {
public:
    int helper(vector<int>& piles, int h, int m) {
        int ans = 0;
        for(int p : piles) {
            ans += (p + m - 1) / m;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int m = l + (r - l) / 2;
            if(helper(piles, h, m) > h) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
