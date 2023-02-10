class Solution {
public:
    string findContestMatch(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++) {
            ans.push_back(to_string(i));
        }
        while(ans.size() > 1) {
            vector<string> temp(ans.begin(), ans.end());
            ans.clear();
            for(int i = 0; i < temp.size()/2; i++) {
                ans.push_back("(" + temp[i] + "," + temp[temp.size() - 1 - i] + ")");
            }
        }
        return ans[0];
    }
};
