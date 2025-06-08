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



class Solution {
public:
    void helper(vector<int> &ans, int num, int n) {
        if(num > n)
            return;
        ans.push_back(num);
        for(int i = 0; i <= 9; i++) {
            helper(ans, num * 10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++)
            helper(ans, i, n);
        return ans;
    }
};
