class Solution {
public:
    int getMaxCount(vector<int> &counter) {
        int maxCount = 0;
        for(int i : counter)
            maxCount = max(maxCount, i);
        return maxCount;
    }
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0, end = 0, ans = 0;
        for(char c : s) {
            counts[c - 'A']++;
            end++;
            while(end - start - getMaxCount(counts) > k) {
                counts[s[start++]-'A']--;
            }
            ans = max(ans, end - start);
        }
        return ans;

    }
};
