class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0')
            return 0;
        vector<int> DP(n);
        DP[0] = 1;
        for(int i = 1; i < n; i++) {
            int first = s[i] - '0';
            int second = (s[i-1] - '0')*10 + first;
            if(first <= 9 && first > 0)
                DP[i] += DP[i-1];
            if(second <= 26 && second > 9)
                DP[i] += i - 2 >= 0 ? DP[i-2] : 1;
        }
        return DP[n-1];
    }
};
