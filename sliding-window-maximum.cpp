class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!q.empty() && q.front() <= i - k)
                q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[q.front()]);    
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ms.insert(nums[i]);
            if(ms.size() > k) {
                ms.erase(ms.find(nums[i-k]));
            }
            if(i >= k - 1)
                ans.push_back(*ms.rbegin());
                
        }
        return ans;
    }
};
