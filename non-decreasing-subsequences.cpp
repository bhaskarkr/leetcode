class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int num : nums) {
            int len = ans.size();
            for(int i = 0; i < len; i++) {
                vector<int> temp(ans[i].begin(), ans[i].end());
                if(temp.empty() || temp.back() <= num)
                    temp.push_back(num);
                ans.push_back(temp);
            }
        }
        set<vector<int>> unique(ans.begin(), ans.end());
        ans = vector<vector<int>> (unique.begin(), unique.end());
        vector<vector<int>> finalAns;
        for(auto i = ans.begin(); i < ans.end(); i++) {
            if((*i).size() >= 2) {
                finalAns.push_back(*i);
            }   
        }
        return finalAns;
    }
};
