class Solution {
public:
    int tribonacci(int n) {
        vector<int> ans = {0, 1, 1, 2};
        if(n < 3)
            return ans[n];
        while(n - 3) {
            swap(ans[0], ans[1]);
            swap(ans[1], ans[2]);
            swap(ans[2], ans[3]);
            ans[3] = ans[0]+ans[1]+ans[2];
            n--;
        }
        return ans.back();
    }
};
