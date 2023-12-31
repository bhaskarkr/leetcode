class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> index(26, -1);
        for(int i = 0; i < s.length(); i++) {
            if(index[s[i] - 'a'] == -1)
                index[s[i] - 'a'] = i;
            else
                ans = max(i - index[s[i] - 'a'] - 1, ans);
        }
        return ans;
    }
};
