class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = *nums.rbegin() - (*nums.begin());
        while(l < r) {
            int m = l + (r - l) / 2;
            int c = 0;
            for(int i = 0; i < nums.size(); i++)
                c += (upper_bound(nums.begin(), nums.end(), nums[i] + m) - nums.begin()) - i - 1;
            if(c >= k)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = *nums.rbegin() - (*nums.begin());
        while(l < r) {
            int m = l + (r - l) / 2;
            int c = 0;
            for(int i = 1; i < nums.size(); i++) {
                for(int j = i - 1; j >= 0; j--) {
                    if(nums[i] - nums[j] > m)
                        break;
                    c++;
                }
            }
            if(c >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
