class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> wagePerQuality;
        for(int i = 0 ; i  < n; i++) {
            wagePerQuality.emplace_back((1.0 * wage[i])/ quality[i], quality[i]);
        }

        sort(wagePerQuality.begin(), wagePerQuality.end());
        double ans = INT_MAX;
        int qSum = 0;
        priority_queue<int> pq;
        for(auto wPerQ : wagePerQuality) {
            qSum += wPerQ.second;
            pq.push(wPerQ.second);
            if(pq.size() > k) {
                qSum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = min(ans, qSum * wPerQ.first);
        }

        return ans;

    }
};
