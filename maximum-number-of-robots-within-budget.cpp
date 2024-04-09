class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0;
        long sum = 0;
        multiset<int> ms;
        for(int l = 0, r = 0; r < chargeTimes.size(); r++) {
            sum += runningCosts[r];
            ms.insert(chargeTimes[r]);
            while(!ms.empty() && l <= r && (*ms.rbegin()) + (r - l + 1) * sum > budget) {
                sum -= runningCosts[l];
                ms.erase(ms.find(chargeTimes[l]));
                l++;
            }
            ans = max(ans, r - l + 1); 
        }
        return ans;
    }
};


class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0;
        long sum = 0;
        priority_queue<pair<int, int>> pq;
        for(int l = 0, r = 0; r < chargeTimes.size(); r++) {
            sum += runningCosts[r];
            pq.push({chargeTimes[r], r});
            while(!pq.empty() && pq.top().second < l)
                pq.pop();
            while(!pq.empty() && l <= r && pq.top().first + (r - l + 1) * sum > budget) {
                sum -= runningCosts[l];
                l++;
            }
            ans = max(ans, r - l + 1); 
        }
        return ans;
    }
};
