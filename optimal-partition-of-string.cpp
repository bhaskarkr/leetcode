class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> counter;
        int ans = 0;
        for(char c : s) {
            if(counter[c] > 0) {
                counter.clear();
                ans++;
            }
            counter[c]++;
        }
        return ans + 1;
    }
};
