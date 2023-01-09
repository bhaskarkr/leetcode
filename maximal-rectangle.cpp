class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> histogram(col + 1);
        int ans = 0;
        for(int r = 0; r < row; r++) {
            stack<int> histogramHeights;
            histogramHeights.push(-1);
            for(int c = 0; c <= col; c++) {
                if(c < col)
                    histogram[c] = matrix[r][c] == '1' ? histogram[c] + 1 : 0;
                while(histogramHeights.top() != -1 && (c == col || histogram[histogramHeights.top()] >= histogram[c])) {
                    int height = histogram[histogramHeights.top()];
                    histogramHeights.pop();
                    int width = (c - 1) - histogramHeights.top();
                    ans = max(ans, height * width);
                }
                histogramHeights.push(c);
            }
        }
        return ans;
    }
};
