class Solution {
public:
    long getCost(vector<int>& nums, vector<int>& cost, int m) {
        long sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += cost[i] * 1L * abs(m - nums[i]);
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l = INT_MAX, r = INT_MIN;
        long ans = 0;
        for(int num : nums)
            l = min(l, num), r = max(r, num);
        while(l < r) {
            int m1 = (l + r) / 2;
            int m2 = m1 + 1;
            long c1 = getCost(nums, cost, m1);
            long c2 = getCost(nums, cost, m2);
            ans = min(c1, c2);
            if(c1 < c2)
                r = m1;
            else
                l = m2;
        } 
        return ans;
    }
};
