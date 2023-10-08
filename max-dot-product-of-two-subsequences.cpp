class Solution {
public:
    int DP[501][501][2];
    int recursion(int i, int j, int found, vector<int>& nums1, vector<int>& nums2) {
        if(i == nums1.size() || j == nums2.size()) {
            return found ? 0 : INT_MIN;
        }
        if(DP[i][j][found] != -1) {
            return DP[i][j][found];
        }
        int ans = nums1[i] * nums2[j] + recursion(i + 1, j + 1, 1, nums1, nums2);
        ans = max(ans, recursion(i + 1, j, found, nums1, nums2));
        ans = max(ans, recursion(i, j + 1, found, nums1, nums2));
        return DP[i][j][found] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(DP, -1, sizeof(DP));
        return recursion(0, 0, 0, nums1, nums2);
    }
};
