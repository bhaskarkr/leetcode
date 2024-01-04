class Solution {
public:
    vector<vector<int>> memo;
    int solver(string s, int K, int i) {
        if(i == s.length())
            return 0;
        if(s.length() - i <= K)
            return 0;
        int c = 1, k = K;
        if(memo[i][k] != -1)
            return memo[i][k];
        int ans = k ? solver(s, k - 1, i + 1) : 101;
        for(int j = i + 1; j <= s.length(); j++) {
            ans = min(ans, 1 + ((c > 99) ? 3 : (c > 9 ? 2 : (c > 1 ? 1 : 0))) + solver(s, k, j));
            if(j < s.length() && s[i] == s[j])
                c++;
            else if(--k < 0)
                break;
        }
        return memo[i][K] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memo.resize(101, vector<int> (101, -1));
        return solver(s, k, 0);
    }
};
// class Solution {
// public:
//     int ans = INT_MAX;
//     int helper(string s, int k) {
//         int n = s.length(), ans = 0, c = -1;
//         for(int i = 0; i <= n; i++) {
//             if(i < n) {
//                 if(i > 0 && s[i] == s[i-1])
//                     c++;
//                 else {
//                     if(c == -1)
//                         c = 0;
//                     else 
//                         ans += c == 1 ? 1 : 1 + to_string(c).length();
//                     c = 1;
//                 }
//             } else
//                 ans += c == 1 ? 1 : 1 + to_string(c).length();
//         }
//         return ans;
//     }
//     int solver(string s, int k, int index) {
//         if(k >= s.length())
//             return 0;
//         if(k == 0 || index >= s.length())
//             return ans = min(helper(s, k), ans);
//         return min(solver(s, k, index + 1), solver(s.substr(0, index) + s.substr(index + 1), k - 1, index));
//     }
//     int getLengthOfOptimalCompression(string s, int k) {
//         return solver(s, k, 0);
//     }
// };
