class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = neededTime.size(), minCost = 0, sum = 0;
        for(int i = 0; i < n;) {
            minCost = neededTime[i];
            i++;
            while(i < n && colors[i] == colors[i-1]) {
                if(neededTime[i] < minCost)
                    ans += neededTime[i];
                else {
                    ans += minCost;
                    minCost = neededTime[i];
                }
                i++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans = 0;
        for(int i = 0; i < n;) {
            int firstColor = colors[i];
            int total = neededTime[i];
            int maxCost = neededTime[i];
            i++;
            while(i < n && colors[i] == firstColor) {
                maxCost = max(maxCost, neededTime[i]);
                total += neededTime[i];
                i++;
            }
            ans += total - maxCost;
        }
        return ans;
    }
};
