class Solution {
public:
    
    pair<int, int> getHourAndMinute(string time) {
        int split = time.find(':');
        int hour = stoi(time.substr(0, split));
        int minute = stoi(time.substr(split + 1));
        return {hour, minute};
    }
    
    int getInMinutes(string t) {
        pair<int, int>  pairTime = getHourAndMinute(t);
        return pairTime.first*60 + pairTime.second;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int minDay = 24*60;
        vector<bool> times(minDay);
        for(string time : timePoints) {
            if(times[getInMinutes(time)])
                return 0;
            times[getInMinutes(time)] = true;
        } 
        int ans = INT_MAX;
        int n = timePoints.size();
        int first = INT_MAX;
        int prev = -86400;
        for(int i = 0; i < minDay; i++) {
            if(times[i]) {
                if(first == INT_MAX)
                    first = i;
                ans = min(ans, i - prev);
                prev = i;
            }
        }
        ans = min(ans, minDay + first - prev);
        return ans;
    }
};
