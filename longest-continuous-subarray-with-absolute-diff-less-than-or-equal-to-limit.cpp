class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDq, maxDq;
        int ans = 1;
        int start = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(!minDq.empty() && minDq.back() > nums[i])
                minDq.pop_back();
            while(!maxDq.empty() && maxDq.back() < nums[i])
                maxDq.pop_back();
            minDq.push_back(nums[i]);
            maxDq.push_back(nums[i]);
            while(maxDq.front() - minDq.front() > limit) {
                if(maxDq.front() == nums[start])
                    maxDq.pop_front();
                if(minDq.front() == nums[start])
                    minDq.pop_front();
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
