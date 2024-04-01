class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1, ans = 0;
        for(int r = 0; r < s.length(); r++) {
            if(s[r] == 'a') 
                a = r;
            else if(s[r] == 'b')
                b = r;
            else if(s[r] == 'c')
                c = r;
            ans += min(a, min(b, c)) + 1;
        }
        return ans;

    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0, ans = 0;
        for(int l = 0, r = 0; r < s.length(); r++) {
            a += s[r] == 'a';
            b += s[r] == 'b';
            c += s[r] == 'c';
            while(a * b * c) {
                a -= s[l] == 'a';
                b -= s[l] == 'b';
                c -= s[l] == 'c';
                l++;
            }
            ans += l;
        }
        return ans;

    }
};
