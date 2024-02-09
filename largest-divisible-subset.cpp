class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ml = 0;
        vector<int> ans;
        vector<pair<int, int>> nexts(n);
        for(int i = n - 1; i >= 0; i--) {
            int next = -1;
            int l = 0;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] % nums[i] == 0 && nexts[j].first > l) {
                    next = j;
                    l = nexts[j].first;
                }
            }
            ml = max(l + 1, ml);
            nexts[i] = {l + 1, next};
        }
        for(int i = 0; i < n; i++) {
            if(nexts[i].first == ml) {
                int curr = i;
                ans.push_back(nums[curr]);
                while(nexts[curr].second != -1) {
                    curr = nexts[curr].second;
                    ans.push_back(nums[curr]);
                }
                break;
            }
        }
        return ans;
    }
};
