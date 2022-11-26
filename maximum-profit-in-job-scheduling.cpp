class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        map<int, int> DP;
        vector<vector<int>> data(n);
        for(int i = 0; i < n; i++) {
            data[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(data.begin(), data.end());
        DP[0] = 0;
        for(int i = 0; i < n; i++) {
            auto upperB = DP.upper_bound(data[i][1]);
            auto lastEle = prev(upperB);
            int newProfit = lastEle->second + data[i][2];
            if(newProfit > DP.rbegin()->second)
                DP[data[i][0]] = newProfit;
        }
        
        return DP.rbegin()->second;
    }
};
