class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> data;
        int n = profits.size();
        for(int i = 0; i < n; i++) {
            data.push_back({capital[i], profits[i]});
        }
        sort(data.begin(), data.end());
        priority_queue<int> PQ;
        int i = 0;
        while (k--) {
            while(i < n & data[i].first <= w) {
                PQ.push(data[i].second);
                i++;
            }
            if(!PQ.empty()) {
                w += PQ.top();
                PQ.pop();
            }
        }
        return w;
    }
};
