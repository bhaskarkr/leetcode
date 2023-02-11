class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans = {1};
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'D') {
                int start = i;
                while(i < s.length() && s[i] == 'D') {
                    ans.push_back(i+2);
                    i++;
                }
                i--;
                reverse(ans.begin()+start, ans.end());
               
            } else {
                ans.push_back(i+2);
            }
        }
        return ans;
    }
};
