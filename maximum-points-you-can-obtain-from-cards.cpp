class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        ans = sum;
        int i = k-1;
        for(int j = cardPoints.size() - 1; i >= 0;) {
            sum += cardPoints[j--];
            sum -= cardPoints[i--];
            ans = max(ans, sum);
        }
        return ans;
    }
};
