class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] <= m)
                continue;
            m++;
        }
        return m;
    }
};
