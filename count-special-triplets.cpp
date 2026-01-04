class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long> before, after;
        long ans = 0, mod = 1000000007;
        for(int num : nums) {
            after[num]++;
        }
        for(int num : nums) {
            after[num]--;
            ans = (ans + (before[2 * num] * after[2 * num]) % mod) % mod; 
            before[num]++;
        }
        return ans;
    }
};
