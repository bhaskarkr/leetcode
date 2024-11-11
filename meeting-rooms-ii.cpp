class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int ans = 0, count = 0;
        for(auto interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            count += it->second;
            ans = max(count, ans);
        }
        return ans;
    }
};
