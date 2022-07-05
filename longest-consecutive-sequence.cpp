class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int ans = 0;
        for(int num : S) {
            if(S.find(num - 1) == S.end()) {
                int k = num + 1;
                while(S.find(k) != S.end())
                    k++;
                ans = max(ans, k - num);    
            }
        }
        return ans;
    }
};
