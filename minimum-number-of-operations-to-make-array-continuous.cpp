class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxLen = 0, n = nums.size();
        set<int> s(nums.begin(), nums.end());
        vector<int> un(s.begin(), s.end());
        for(int i = 0; i < un.size(); i++) {
            int c = upper_bound(un.begin(), un.end(), un[i] +  n - 1) - un.begin();
            maxLen = max(maxLen, c - i);
        }
        return n - maxLen;
    }
};
