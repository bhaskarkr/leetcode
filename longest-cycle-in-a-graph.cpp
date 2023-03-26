class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n = edges.size();
        int time = 1;
        vector<int> visitTime(n);
        for(int i = 0; i < n; i++) {
            if(visitTime[i] != 0)
                continue;
            int currStartTime = time;
            int currIndex = i;
            while(currIndex != -1 && visitTime[currIndex] == 0) {
                visitTime[currIndex] = time++;
                currIndex = edges[currIndex];
            }
            if(currIndex != -1 && visitTime[currIndex] >= currStartTime) 
                ans = max(ans, time - visitTime[currIndex]);
        }
        return ans;
    }
};
