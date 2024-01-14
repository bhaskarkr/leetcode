class Solution {
public:
    int merge(vector<long>& sums, int lower, int upper, int s, int m, int e) {
        int index = 0, l = s, r = m + 1, count = 0, lowerIndex = m + 1, higherIndex = m + 1;
        vector<long> temp(e - s + 1);
        for(int left = s; left <= m; left++) {
            while(lowerIndex <= e && sums[lowerIndex] - sums[left] < lower)
                lowerIndex++;
            while(higherIndex <= e && sums[higherIndex] - sums[left] <= upper)
                higherIndex++;
            count += higherIndex - lowerIndex;
        } 
        while(l <= m && r <= e) {
            if(sums[l] < sums[r]) {
                temp[index++] = sums[l++];
            } else {
                temp[index++] = sums[r++];
            }
        }
        while(l <= m) {
            temp[index++] = sums[l++];
        }
        while(r <= e) {
            temp[index++] = sums[r++];
        }
        index = 0;
        while(s <= e)
            sums[s++] = temp[index++];
        return count;
    }
    int mergeSort(vector<long>& sums, int lower, int upper, int s, int e) {
        if(s >= e)
            return 0;
        long m = s + (e - s) / 2;
        return mergeSort(sums, lower, upper, s, m) + mergeSort(sums, lower, upper, m + 1, e) + merge(sums, lower, upper, s, m, e);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1);
        for(int i = 0; i < n; i++)
            sums[i + 1] += sums[i] + nums[i];
        return mergeSort(sums, lower, upper, 0, n);
    }
};
