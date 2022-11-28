class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loser;
        set<int> all;
        for(auto match : matches) {
            all.insert(match[0]);
            all.insert(match[1]);
            loser[match[1]]++;
        }
        
        vector<int> zeroLoss, oneLoss;
        
        for(auto id : all) {
            if(loser[id] == 0) {
                zeroLoss.push_back(id);
            } else if(loser[id] == 1)
                oneLoss.push_back(id);
        }
    
        return {zeroLoss, oneLoss};
    }
};
