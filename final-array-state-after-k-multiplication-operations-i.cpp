class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        vector<int> ans(nums.size());
        while(k--) {
            auto top = pq.top();
            pq.pop();
            top.first *= multiplier; 
            pq.push(top);
        }
        while(!pq.empty()) {
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while(k--) {
            auto top = pq.top();
            pq.pop();
            top.first *= multiplier; 
            nums[top.second] = top.first;
            pq.push(top);
        }
        return nums;
    }
};
