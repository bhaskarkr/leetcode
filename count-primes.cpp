class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        if(n < 3)
            return 0; 
        vector<bool> res(n, true);
        res[0] = false;
        res[1] = false;
        for(int i = 2; i < n; i++) {
            if(res[i]) {
                ans++;
                for(int j = i; j < n; j += i)
                    res[j] = false;
            }
        }
        return ans;
    }
};
