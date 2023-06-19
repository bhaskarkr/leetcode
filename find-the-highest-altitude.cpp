class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int prev = 0;
        for(int num : gain) {
            prev += num;
            ans = max(ans, prev);
        }
        return ans;
    }
};
