class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0.0;
        int ones = 0;
        auto getIncrement = [&](double num, double deno) {
            return ((num + 1) / (deno + 1)) -  (num / deno);
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for(auto c : classes)
            pq.push({getIncrement(c[0], c[1]), {c[0], c[1]}});
        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();
            pq.push({getIncrement(top.second.first + 1, top.second.second + 1), {top.second.first + 1, top.second.second + 1}});
        }
        while(!pq.empty()) {
            ans += (double) pq.top().second.first / pq.top().second.second;
            pq.pop();
        }
        return ans / classes.size();
    }
};
