class Solution {
public:
    int numSplits(string s) {
        vector<int> preCount(s.length());
        unordered_map<int, int> uniqueChar;
        int i = 0;
        for(char c : s) {
            uniqueChar[c]++;
            preCount[i++] = uniqueChar.size();
        }
        int ans = 0;
        unordered_map<int, int> tempChar;
        for(i = s.length() - 1; i > 0; i--) {
            char c = s[i];
            tempChar[c]++;
            if(tempChar.size() == preCount[i-1])
                ans++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int numSplits(string s) {
//         unordered_map<int, int> uniqueChar;
//         for(char c : s) {
//             uniqueChar[c]++;
//         }
//         int ans = 0;
//         unordered_map<int, int> tempChar;
//         for(char c : s) {
//             tempChar[c]++;
//             uniqueChar[c]--;
//             if(uniqueChar[c] == 0)
//                 uniqueChar.erase(c);
//             if(tempChar.size() == uniqueChar.size())
//                 ans++;
//         }
//         return ans;
//     }
// };


