class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        queue<char> Q;
        unordered_map<char, int> counter;
        int n = s.length(), j = 0, uniqChar = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            counter[s[i]]++;
            if(counter[s[i]] == 1) {
                uniqChar++;
            }
            while(uniqChar > 2) {
                counter[s[j]]--;
                if(counter[s[j]] == 0)
                    uniqChar--;
                j++;
            }
            ans = max(ans, i - j + 1);
        } 
        return ans;
    }
};
