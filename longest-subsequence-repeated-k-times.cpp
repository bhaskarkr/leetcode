class Solution {
public:

    bool possible(string s, string t, int k) {
        int cnt = 0, tl = 0;
        for(char c : s) {
            if(c == t[tl]) {
                tl++;
            } 
            if(tl == t.length())
                k--, tl = 0;

            if(k == 0)
                return true;
        }   
        return k <= 0;
    }

    string helper(string s, string t, int k) {
        string ss = "";
        for(char c = 'z'; c >= 'a'; c--) {
            if(possible(s, t + c, k)) {
                t += c;
                string temp = c + helper(s, t, k);
                if(temp.length() > ss.length()) {
                    ss = temp;
                }
                t.pop_back();
            }
        }
        return ss;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        return helper(s, "", k);
    }
};
