class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> scoreIndex;
        for(int i = 0; i < score.size(); i++) {
            scoreIndex.push_back({score[i], i});
        }
        sort(scoreIndex.rbegin(), scoreIndex.rend());
        vector<string> ans(score.size());
        for(int i = 0; i < score.size(); i++) {
            if(i < 3) {
                if(i == 0)
                    ans[scoreIndex[i].second] = "Gold Medal";
                else if(i == 1)
                    ans[scoreIndex[i].second] = "Silver Medal";
                else
                    ans[scoreIndex[i].second] = "Bronze Medal";
            } else {
                ans[scoreIndex[i].second] = to_string(i+1);
            }
        }
        return ans;
    }
};
