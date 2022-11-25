class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> type(candyType.begin(), candyType.end());
        return min(type.size(), candyType.size()/2);
    }
};
