class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> countMap;
        for(int num : hand) {
            countMap[num]++;
        }
        for(auto [k, v] : countMap) {
            if(v > 0) {
                for(int i = 1; i < groupSize; i++) {
                    countMap[k + i] -= v;
                    if(countMap[k + i] < 0)
                        return false;   
                }
                countMap[k] = 0;
            }
        }
        return true;
    }
};
