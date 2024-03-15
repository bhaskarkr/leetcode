class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 0, eq = 0;
        vector<int> p1(n), p2(n);
        unordered_map<int, int> diff;
        diff[0] = -1;
        for(int i = 0; i < n; i++) {
            if(i) {
                p1[i] += p1[i - 1];
                p2[i] += p2[i - 1];
            }
            p1[i] += nums1[i];
            p2[i] += nums2[i];
            if(diff.find(p1[i] - p2[i]) == diff.end())
                diff[p1[i] - p2[i]] = i;
            else
                ans = max(ans, i - diff[p1[i] - p2[i]]);
        }
        return ans;
    }
};
