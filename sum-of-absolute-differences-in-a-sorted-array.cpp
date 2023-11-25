class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& t) {
        int n = t.size();
        vector<int> presum(n);
        long sum = accumulate(t.begin(), t.end(), 0);
        long ls = 0, rs = sum;
        for(int i = 0; i < n ; i++) {
            long smaller = i;
            long greater = (n - smaller);
            long smallerSum =  smaller * t[i] - ls;
            long greaterSum = rs - greater * t[i];
            long val = smallerSum + greaterSum;
            ls += t[i];
            rs -= t[i];
            t[i] = val;
        }
        return t;
    }
};

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(nums.begin(), nums.end()), presum(n);
        presum[0] = t[0];
        for(int i = 1; i < n; i++) {
            presum[i] += presum[i-1] + t[i];
        }
        for(int i = 0; i < n ; i++) {
            auto it = lower_bound(t.begin(), t.end(), nums[i]);
            long smaller = (it - t.begin());
            long greater = (n - 1 - smaller);
            long smallerSum =  smaller ? smaller * nums[i] - presum[smaller - 1] : 0;
            long greaterSum = greater ? presum.back() - presum[n - 1 - greater] - greater * nums[i] : 0;
            long val = smallerSum + greaterSum;
            nums[i] = val;
        }
        return nums;
    }
};
