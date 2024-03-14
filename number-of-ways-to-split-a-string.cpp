class Solution {
public:
    int numWays(string s) {
        vector<long> presum(s.length());
        int mod = 1e9 + 7;
        presum[0] = s[0] - '0';
        for(int i = 1; i < s.length(); i++) 
            presum[i] = presum[i-1] + s[i] - '0';
        long maxC = presum.back();
        if(maxC % 3 != 0)
            return 0;
        if(maxC == 0)
            return (((s.length() - 1L) * (s.length() - 2L)) / 2 ) % mod;
        long split = maxC / 3, ans = 1;
        vector<long> vals(2, 0);
        for(int i = 0; i < presum.size() - 1; i++)
            if((presum[i] / split) > 0 && presum[i] % split == 0 && (presum[i] / split) < 3)
                vals[(presum[i] / split) - 1]++;
        for(long t : vals)
            ans = (ans * t) % mod; 
        return ans;
    }
};
