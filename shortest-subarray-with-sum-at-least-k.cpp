class Solution {
public:
    int shortestSubarray(vector<int>& num, int k) {
        long ans = INT_MAX;
        vector<long> nums(num.begin(), num.end());
        deque<long> q;
        for(int i = 0; i < nums.size(); i++) {
            if(i)
                nums[i] += nums[i-1];
            if(nums[i] >= k)
                ans = min(ans, i + 1L);
            while(!q.empty() && nums[i] - nums[q.front()] >= k)
                ans = min(ans, i - q.front()), q.pop_front();
            while(!q.empty() && nums[i] <= nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
