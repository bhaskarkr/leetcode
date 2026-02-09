class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> DP(s.length() + 1);
        int b = 0;
        for(int i = 1; i <= s.length(); i++) {
            if(s[i-1] == 'b') {
                DP[i] = DP[i-1];
                b++;
            } else {
                DP[i] = min(b, DP[i-1] + 1);
            }
        }
        return DP.back();
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int deleteCount = 0;
        int b = 0;
        for(int i = 1; i <= s.length(); i++) {
            if(s[i-1] == 'b') {
                b++;
            } else {
                deleteCount = min(b, deleteCount + 1);
            }
        }
        return deleteCount;
    }
};
