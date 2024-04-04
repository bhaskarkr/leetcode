class Solution {
public:
    int maxDepth(string s) {
        int o = 0, ans = 0;
        for(char c : s) {
            if(c == '(')
                o++;
            else if(c == ')')
                o--;
            ans = max(ans, o);
        }
        return ans;
    }
};
