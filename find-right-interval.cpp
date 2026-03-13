class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int , int> m;
        vector<int> ans(intervals.size());
        for(int i = 0; i < intervals.size(); i++) {
            m[intervals[i][0]] = i;
        }
        for(int i = 0; i < intervals.size(); i++) {
            auto itr = m.lower_bound(intervals[i][1]);
            if(itr == m.end())
                ans[m[intervals[i][0]]] = -1;
            else 
                ans[m[intervals[i][0]]] = itr->second;
        }
        return ans;
    }
};
