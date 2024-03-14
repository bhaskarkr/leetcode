class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>& cookies, int c, int k, vector<int> allocated) {
        if(c == cookies.size()) {
            ans = min(ans, *max_element(allocated.begin(), allocated.end()));
            return;
        }
        for(int i = 0; i < k; i++) {
            allocated[i] += cookies[c];
            helper(cookies, c + 1, k, allocated);
            allocated[i] -= cookies[c];
            if(allocated[i] == 0)
                break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> allocated(k, 0);
        helper(cookies, 0, k, allocated);
        return ans;
    }
};
