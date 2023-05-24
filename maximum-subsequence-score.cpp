class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums1.size(); i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> PQ;
        long ans = 0, sum = 0;
        for(pair curr : pairs) {
            PQ.push(curr.second);
            sum += curr.second;
            while(PQ.size() > k) {
                sum -= PQ.top();
                PQ.pop();
            }
            if(PQ.size() == k) {
                ans = max(ans, sum*curr.first);
            }
        }
        return ans;
    }
};
