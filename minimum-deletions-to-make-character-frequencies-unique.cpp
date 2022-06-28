class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        for(char c : s)
            count[c-'a']++;
        sort(count.begin(), count.end());
        int ans = 0;
        for(int i = 24; i >=0; i--) {
            if(count[i] >= count[i+1]) {
                int prev = count[i];
                count[i] = max(0, count[i+1] - 1);
                ans += prev - count[i];
            }
        }
        return ans;
    }
};