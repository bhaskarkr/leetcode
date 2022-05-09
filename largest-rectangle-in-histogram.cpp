class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        stk.push(-1);
        int ans = 0;
        for(int i = 0; i  <= n; i++) {
            while(stk.top() != -1 && (i == n || heights[stk.top()] > heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = i - stk.top() - 1;
                ans = max(ans, h*w);
            }
            stk.push(i);
        }
        return ans;
    }
};
