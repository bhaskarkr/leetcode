class Solution {
public:
    string robotWithString(string s) {
        string ans;
        string best = s;
        for(int i = s.length() - 2; i >= 0; i--) {
            best[i] = min(best[i+1], s[i]);
        }
        char minC = best[0];
        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == minC) {
                ans.push_back(c);
            } else {
                while(!stk.empty() && stk.top() <= best[i]) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
                stk.push(c);
            }
        }
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
