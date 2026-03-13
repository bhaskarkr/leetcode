class Solution {
public:
    int countTime(string t) {
        int ans = 1;
        if(t[0] == '?') {
            ans *= t[1] == '?' ? 24 : t[1] < '4' ? 3 : 2;
        } else if(t[1] == '?') {
            ans *= t[0] == '2' ? 4 : 10;
        } 
        if(t[3] == '?') {
            ans *= t[4] == '?' ? 60 : 6;
        } else if(t[4] == '?')
            ans *= 10;
        return ans;
    }
};
