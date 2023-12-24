class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), odd1 = 0, even1 = 0, nextOdd = 1, nextEven = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == nextOdd) odd1++;
            if(s[i] - '0' == nextEven) even1++;
            nextOdd ^= 1;
            nextEven ^= 1;
        }
        return min(n - odd1, n - even1);
    }
};
