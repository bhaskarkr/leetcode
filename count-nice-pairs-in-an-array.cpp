class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long> mp;
        long ans = 0, mod = 1e9 + 7;
        for(int num : nums) {
            int t = num, rev = 0;
            while(t) {
                rev = rev * 10 + t % 10;
                t /= 10;
            }
            ans = (ans + mp[num - rev]) % mod;
            mp[num - rev]++;
        } 
        return ans;
    }
};
