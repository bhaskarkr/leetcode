class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0, ones = 0, right = 0;
        vector<int> ans(boxes.length());
        for(int i = 0; i < boxes.length() - 1; i++) {
            ones += (boxes[i] - '0');
            ans[i + 1] = ans[i] + ones;
        }
        ones = 0;
        /**
        *   1   1   0   1
        *   1   3   5   
        *       4   2   1   
        *   4   3   4   5
        */
        for(int i = boxes.length() - 1; i >= 0; i--) {
            ans[i] = right + (ans[i]);
            ones += (boxes[i] - '0');
            right += ones;
        }
        return ans;
    }
};
