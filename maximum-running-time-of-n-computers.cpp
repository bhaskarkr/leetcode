class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        using ll = long long;
        ll  l = 0, r = accumulate(batteries.begin(), batteries.end(), 0LL) / n, ans = 0;
        while(l <= r) {
            ll m = l + (r - l) / 2;
            ll s = 1;
            ll minutes = 0;
            for(int &bat : batteries)
                minutes += min((ll)bat, m);
            if(minutes >= n * m) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }

        }
        return ans;
    }   
};
