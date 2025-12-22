class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> answer(strs.size());
        int ans = 0;
        for(int i = 0; i < strs[0].length(); i++) {
            bool found = false;
            for(int j = 1; j < strs.size(); j++) {
                if(!answer[j] && strs[j][i] < strs[j-1][i]) {
                    found = true;
                    ans++;
                    break;
                } 
            }
            if(found)
                continue;
            for(int j = 1; j < strs.size(); j++)
                answer[j] = answer[j] || strs[j][i] > strs[j-1][i];
        }
        return ans;
    }
};
