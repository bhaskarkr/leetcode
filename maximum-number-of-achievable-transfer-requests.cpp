class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int nr = requests.size(), ans = 0;
        for(int mask = 1; mask < (1 << nr); mask++) {
            vector<int> degree(n);
            for(int j = 0; j < nr; j++) {
                if((1 << j) & (mask)) {
                    degree[requests[j][0]]--;
                    degree[requests[j][1]]++;
                }    
            }
            if(count(degree.begin(), degree.end(), 0) == n)
                ans = max(ans,  __builtin_popcount(mask));
        }
        return ans;
    }
};
