class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int cst : costs) {
            if(cst > coins)
                break;
            coins -= cst;
            ans++;
        }
        return ans;
    }
};
