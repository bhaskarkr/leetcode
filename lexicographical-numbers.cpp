class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= min(n, 9); i++) {
            ans.push_back(i);
            helper(i, ans, n);
        }
        return ans;
    }
    void helper(int num, vector<int> &ans, int n) {
        for(int i = 0; i < 10; i++) {
            int newNum  = num * 10 + i;
            if(newNum <= n) {
                ans.push_back(newNum);
                helper(newNum, ans, n);
           }
        }
    }
};
