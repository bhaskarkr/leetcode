class Solution {
public:
    int maxDifference(string s) {
        vector<int> counter(26);
        int ans = 0;
        for(char c : s)
            counter[c - 'a']++;
        int maxOdd = 0, maxEven = INT_MAX;
        for(int n : counter) {
            if(n%2)
                maxOdd = max(maxOdd, n);
            else if(n > 0)  
                maxEven = min(maxEven, n);
        }
        return maxOdd - maxEven;
    }
};
