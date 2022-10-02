class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long> DP(target + 1);
        DP[0] = 1;
        for(int dice = 0; dice < n; dice++) {
            vector<long> temp(target + 1);
            for(int face = 1; face <= k; face++) {
                for(int j = face; j <= target; j++) {
                    temp[j] = (temp[j] + DP[j - face]) % 1000000007;
                }
            }
            swap(DP, temp);
        }
        return DP[target];
    }
};
