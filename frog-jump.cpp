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
