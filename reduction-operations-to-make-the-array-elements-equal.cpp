class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int, greater<int>> mp;
        for(auto num : nums)
            mp[num]++;
        int ans = 0, s = 0;
        mp.erase(prev(mp.end()));
        for(auto [k, v] : mp) {
            s += v;
            ans += s;
        } 
        return ans;
    }
};
