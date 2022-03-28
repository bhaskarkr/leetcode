class Solution {
public:
    int numSplits(string s) {
        unordered_map<int, int> uniqueChar;
        for(char c : s) {
            uniqueChar[c]++;
        }
        int ans = 0;
        unordered_map<int, int> tempChar;
        for(char c : s) {
            tempChar[c]++;
            uniqueChar[c]--;
            if(uniqueChar[c] == 0)
                uniqueChar.erase(c);
            if(uniqueChar.size() > 0 && tempChar.size() == uniqueChar.size())
                ans++;
        }
        return ans;
    }
};
