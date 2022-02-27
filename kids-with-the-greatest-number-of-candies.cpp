class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxNum = INT_MIN;
        vector<bool> ans(n, true);
        for(auto c : candies) {
            maxNum = max(maxNum, c);
        }
        for(int i = 0; i < n; i++) {
            if(candies[i]+extraCandies < maxNum)
                ans[i] = false;
        }
        return ans;
    }
};
