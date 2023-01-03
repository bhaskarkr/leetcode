class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0; 
        for(int i = 0; i < strs[0].length(); i++) {
            char prev = 'a' - 1;
            for(string &s : strs) {
                if(s[i] < prev) {
                    ans++;
                    break;
                }
                prev = s[i];
            }
        }
        return ans;
    }
};
