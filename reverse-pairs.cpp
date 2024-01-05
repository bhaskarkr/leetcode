class Solution {
public:
    int merge(vector<int>& nums, int s, int m, int e) {
        int i = s, j = m + 1, k = 0, curr = 0, t = 0;
        vector<int> temp(e - s + 1);
        while(i <= m && j <= e) {
            if(nums[i] > 2L * nums[j])
                curr +=  m - i + 1, j++;
            else i++;
        }
        i = s, j = m + 1;
        while(i <= m && j <= e) {
            if(nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i <= m) temp[k++] = nums[i++];
        while(j <= e) temp[k++] = nums[j++];
        for(int t = s; t <= e; t++)
            nums[t] = temp[t-s];
        return curr;
    }
    int  mergeSort(vector<int>& nums, int s, int e) {
        if(s >= e)
            return 0;
        int m = (s + e) / 2;
        return mergeSort(nums, s, m) + mergeSort(nums, m + 1, e) + merge(nums, s, m, e);
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
