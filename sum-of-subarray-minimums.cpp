class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        arr.push_back(0);
        long n = arr.size(), ans = 0;
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                int curr = stk.top();
                stk.pop();
                int left = stk.top();
                int right = i;
                ans += (curr - left) * (right - curr) * 1L * arr[curr];
            }
            stk.push(i);
        }
        return ans % 1000000007;
    }
};

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
