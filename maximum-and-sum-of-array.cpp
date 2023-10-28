class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        nums.resize(2 * numSlots);
        int l = 1, h = (1<<(2 * numSlots)); // 00010... -1 = 000111111
        vector<int> DP(h);
        for(int i = l; i < h; i++) {
            int noOfEle = __builtin_popcount(i); // count set bits
            int maxSlotNumber = (noOfEle + 1) / 2; // for odd we need one extra slot
            for(int j = 0; j < nums.size(); j++) {
                int currEle = (1 << j); // set bit of current element
                if(i & currEle) {
                    // max we can achieve after removing current elenent 
                    // +
                    // keeping nums[j] in the last slot
                    DP[i] = max(DP[i], DP[i ^ currEle] + (nums[j] & maxSlotNumber));
                }
            }
        }
        return DP[h - 1];
    }
};
