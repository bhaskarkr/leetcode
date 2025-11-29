class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> ans = {0, 1};
        for(int i = 2; i <= n; i++) {
            int diff = ans.size(), j = ans.size() - 1;
            while(j >= 0) {
                ans.push_back(ans[j] + diff);
                j--;
            }
        }
        return ans;
    }
};
