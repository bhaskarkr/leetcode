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

class Solution {
public:
    unordered_map<int, int> dp;
    int helper(int index, string &s) {
        if(s.length() > index && s[index] == '0')
            return 0;
        if(s.length() - 1 <= index)
            return 1;
        int curr = 0, num = 0;
        if(dp.find(index) != dp.end())
            return dp[index];
        curr += helper(index + 1, s);
        if(index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
            curr += helper(index + 2, s);
        return dp[index] = curr;
    }
    int numDecodings(string s) {
        return helper(0, s);
    }
};
// class Solution {
// public:
//     unordered_map<int, int> dp;
//     int helper(int index, string &s) {
//         if(s.length() > index && s[index] == '0')
//             return 0;
//         if(s.length() - 1 <= index)
//             return 1;
//         int curr = 0, num = 0, end = index + 2;
//         if(dp.find(index) != dp.end())
//             return dp[index];
//         for(;index < end; index++) {
//             num = num * 10 + (s[index] - '0');
//             if(num > 26 || num < 1)
//                 break;
//             curr += helper(index + 1, s);
//         }
//         return dp[index] = curr;
//     }
//     int numDecodings(string s) {
//         return helper(0, s);
//     }
// };
