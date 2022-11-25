class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        stack<int> stk;
        stk.push(0);
        int n = arr.size();
        vector<long> sums(n);
        for(int i = 1; i < n; i++) {
            while(arr[stk.top()] > arr[i])
                stk.pop();
            int lastMinItem = stk.top();
            sums[i] = sums[lastMinItem] + (i - lastMinItem)*arr[i]*1L;
            stk.push(i);
        }
        
        return accumulate(sums.begin(), sums.end(), 0L)%1000000007;
    }
};
