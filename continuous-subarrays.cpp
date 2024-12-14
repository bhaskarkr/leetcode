class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        long long ans = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(!ms.empty() and ((abs(*ms.begin() - nums[i]) > 2) or (abs(*prev(ms.end()) - nums[i]) > 2)))
                ms.erase(ms.find(nums[j++]));
            ans += i - j + 1;
            ms.insert(nums[i]);
        }
        return ans;
    }
};
