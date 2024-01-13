class Solution {
public:
    vector<vector<int>> DP;
    int helper(vector<int>& stones, int index, int prevStep) {
        if(index == stones.size() - 1)
            return 1;
        if(DP[index][prevStep] != -1)
            return DP[index][prevStep];
        auto itr = lower_bound(stones.begin(), stones.end(), stones[index] + prevStep - 1);
        for(; itr != stones.end() && *itr <= stones[index] + prevStep + 1; itr++) {
            int newIndex = itr - stones.begin();
            if(newIndex <= index)
                continue;
            if(helper(stones, newIndex, stones[newIndex] - stones[index]))
                return 1;
        }
        return DP[index][prevStep] = 0;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] > 1)
            return false;
        int n = stones.size();
        DP.resize(stones.size(), vector<int> (1000, -1));
        return helper(stones, 1, 1) == 1;
    }
};


class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] > 1)
            return false;
        int n = stones.size();
        vector<vector<int>> DP(n, vector<int>(n + 1));
        DP[0][1] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = stones[i] - stones[j];
                if(diff < 0 || diff > n || DP[j][diff] == 0)
                    continue;
                DP[i][diff] = 1;
                if(diff - 1 > 0)
                    DP[i][diff - 1] = 1;
                if(diff + 1 <= n)
                    DP[i][diff + 1] = 1;
            }
        }
        return count(DP.back().begin(), DP.back().end(), 1) > 1;
    }
};
