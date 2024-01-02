class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> c;
        for(auto &num : nums)
            c[num]++;
        vector<vector<int>> ans;
        int j = 0;
        for(auto [k, v] : c) {
            int i = 0;
            while(i < v) {
                if(i >= ans.size())
                    ans.push_back({});
                ans[i].push_back(k);
                i++;
            }
            j++;
        }
        return ans;
    }
};
