class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                // cout<<sum<<" "<<nums[l]<<" "<<nums[r]<<" "<<nums[i]<< endl;
                if(abs(target - sum) < abs(ans-target))
                    ans = sum;
                if(sum == target)
                    return target;
                else if(sum < target) {
                    l++;
                } else 
                    r--;
            } 
        }
        return ans;
    }
};
