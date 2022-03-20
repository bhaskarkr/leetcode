class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> both;
        unordered_map<int, int> top;
        unordered_map<int, int> bot;
        int ans = INT_MAX;
        for(int i = 0; i < tops.size(); i++) {
            top[tops[i]]++;
            bot[bottoms[i]]++;
            if(tops[i] == bottoms[i])
                both[bottoms[i]]++;    
        }
        for(int i = 1; i <= 6; i++) {
            if(top[i] + bot[i] - both[i] == tops.size()) {
                return tops.size() - max(bot[i], top[i]);
            }
        }
        return -1;
    }
};
