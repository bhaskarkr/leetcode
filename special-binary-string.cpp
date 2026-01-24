class Solution {
public:
    string makeLargestSpecial(string s) {
        string ans;
        vector<string> mountains;
        int cnt = 0;
        for(int r = 0, l = 0; r < s.length(); r++) {
            cnt += s[r] == '1' ? 1 : -1;
            if(cnt == 0) {
                mountains.push_back('1' + makeLargestSpecial(s.substr(l+1, r-l-1)) + '0'); 
                l = r + 1;
            }
        }
        sort(mountains.rbegin(), mountains.rend());
        for(string t : mountains)
            ans += t;
        return ans;
    }
};
