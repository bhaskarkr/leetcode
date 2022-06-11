class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i = 0;
        int n = nums.size();
        while(i < n && x > 0) {
            x -= nums[i];
            i++;
        }
        int ans = INT_MAX;
        if(x == 0)
            ans = i;
        else if( i == n)
            return -1;
        i--;
        int j = n - 1;
        while(j >= 0) {
            x -= nums[j];
            while(i >= 0 && x < 0)
                x += nums[i--];
            if(x == 0)
                ans = min(ans, 1 + i + n - j);
            j--;
        }
        return ans != INT_MAX ? ans : -1; 
    }
};
