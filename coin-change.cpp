class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> DP(10001, INT_MAX);
        DP[0] = 0;
        for(int i = 0; i <= amount; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= coins[j] && DP[i - coins[j]] != INT_MAX && DP[i - coins[j]] + 1 < DP[i]) {
                    DP[i] = DP[i - coins[j]] + 1;
                }
            }
        }
        
        
        return DP[amount] == INT_MAX ? -1 : DP[amount] ;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> DP(amount + 1, INT_MAX);
        DP[0] = 1;
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                if(DP[i-coin])
                    DP[i] = min(DP[i-coin] + 1, DP[i]);
            }
        }
        return DP.back() == INT_MAX ? -1 : DP.back() - 1;
    }
};
