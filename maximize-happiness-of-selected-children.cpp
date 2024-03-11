class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0, i = 0;
        while(k--) {
            ans += happiness[i] >= i ? happiness[i] - i : 0;
            i++;
        }   
        return ans;
    }
};
