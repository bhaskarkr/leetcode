class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> data;
        int n = capacity.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            data.push_back(capacity[i] - rocks[i]);
        }
        sort(data.begin(), data.end());
        for(int i = 0; i < n && additionalRocks >= data[i]; i++) {
            additionalRocks -= data[i]; 
            ans++;
        }
        return ans;
    }
};
