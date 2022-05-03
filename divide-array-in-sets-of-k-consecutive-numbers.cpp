class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto num : nums)
            m[num]++;
        for(auto [n, v] : m) {
            if(v>0) {
                for(int i = 1; i < k; i++) {
                    m[n+i] -= v;
                    if(m[n+i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
