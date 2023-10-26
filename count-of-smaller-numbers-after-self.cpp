class Solution {
public:
    vector<int> ans;
    void mergeSort(int s, int m, int e, vector<pair<int , int>> &arr) {
        vector<pair<int , int>> temp(e - s + 1);
        int l = s, r = m + 1, k = 0;
        while(l <= m && r <= e) {
            if(arr[l].first > arr[r].first) {
                ans[arr[l].second] += e - r + 1;
                temp[k++] = arr[l++];
            } else {
                temp[k++] = arr[r++];
            }
        }
        while(l <= m) {
            temp[k++] = arr[l++];
        }

        while(r <= e) {
            temp[k++] = arr[r++];
        }
        for(int i = s; i <= e; i++) {
            arr[i] = temp[i - s];
        }
    }
    void mergeSplit(int s, int e, vector<pair<int , int>> &nums) {
        if(s >= e)
            return;
        int m = (s + e) / 2;
        mergeSplit(m + 1, e, nums);
        mergeSplit(s, m, nums);
        mergeSort(s, m, e, nums);
    }
    vector<int> countSmaller(vector<int>& nums) {
        ans.resize(nums.size());
        vector<pair<int , int>> pairs(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            pairs[i] = {nums[i], i};
        }
        mergeSplit(0, nums.size() - 1, pairs);
        return ans;
    }
};
