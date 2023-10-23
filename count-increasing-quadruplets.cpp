class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<vector<long long >> pre(n, vector<long long>(n)), post(n, vector<long long>(n));;
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                pre[i][j] = pre[i][max(0, j-1)] + (nums[j] < nums[i] ? 1 : 0);
        for(int i = n - 2; i >= 0; i--)
            for(int j = n - 1; j > i; j--)
                post[i][j] = post[i][min(n-1, j + 1)] + (nums[j] > nums[i] ? 1 : 0);
        for(int j = 1; j < n - 1; j++) {
            for(int k = n - 2; k > j; k--) {
                if(nums[j] <= nums[k]) {
                    continue;
                }  
                ans += pre[k][j] * post[j][k];
            }
        }
        return ans;
    }
};
