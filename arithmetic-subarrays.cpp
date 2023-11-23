class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        vector<vector<bool>> m(n, vector<bool>(n));
        for(int i = 0; i < n; i++) {
            set<int> s;
            double sum = 0;
            for(int j = i; j < n; j++) {
                s.insert(nums[j]);
                sum += nums[j];
                if(s.size() == 1)
                    m[i][j] = m[j][i] = true;
                else{
                    int c = j - i + 1;
                    bool len = s.size() == c;
                    bool mod = ((*s.rbegin()) - (*s.begin())) % (j - i) == 0;
                    bool ss = sum == (c*1.0)*(((*s.rbegin()) + (*s.begin())))/2.0;
                    int diff = INT_MIN;
                    auto k = s.begin();
                    if(!len || !ss || !mod)
                        continue;

                    for(;k != prev(s.end()); k++) {
                        if(diff == INT_MIN)
                            diff = (*k - (*next(k)));
                        else if(diff != (*k - (*next(k)))) {
                            break;
                        }
                    }
                    if(k == prev(s.end()))
                        m[i][j] = m[j][i] = true;
                }
            }
        }
        vector<bool> ans(l.size());
        for(int q = 0; q < l.size(); q++) {
            ans[q] = m[l[q]][r[q]];
        }
            
        return ans;
    }
};
