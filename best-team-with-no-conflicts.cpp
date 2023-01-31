class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second <= b.second;
    } 
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> data;
        int maxScore = 0;
        vector<int> DP(ages.size());
        for(int i = 0; i < ages.size(); i++) {
            data.push_back({ages[i], scores[i]});
        }
        sort(data.begin(), data.end());
        for(int i = 0; i < ages.size(); i++) {
            DP[i] = data[i].second;
            for(int j = 0; j < i; j++) {
                if(data[i].second >= data[j].second) {
                    DP[i] = max(DP[i], DP[j] + data[i].second);
                }
            }
            maxScore = max(maxScore, DP[i]);
            
        }
        return maxScore;
    }
};
