class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(startValue < target) {
            target = target%2 ? target + 1 : target / 2;
            ans++;
        }
        return ans + startValue - target;
    }
};
