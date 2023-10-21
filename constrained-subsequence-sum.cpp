class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int ans = nums[0];
        pq.push({nums[0], 0});
        for(int i = 1 ; i < nums.size(); i++) {
            while(pq.top().second < i - k)
                pq.pop();
            int curr = max(nums[i], pq.top().first + nums[i]);
            pq.push({curr, i});
            ans = max(ans, curr);
        }
        return ans;
    }
};
