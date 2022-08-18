class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int num : arr) {
            cnt[num]++;
        }
        priority_queue<pair<int, int>> PQ;
        for(auto [k, v] : cnt) {
            PQ.push({v, k});
        }
        int limit = arr.size() / 2;
        int curr = 0;
        int ans = 0;
        while(!PQ.empty() && curr < limit) {
            auto t = PQ.top();
            PQ.pop();
            curr += t.first;
            ans++;
        }
        return ans;
    }
};
