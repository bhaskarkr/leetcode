class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int ans = 0;
        for(int i = 0, start = 0, end = 0; start < time; start = end, ans++) {
            for(; i < clips.size() && clips[i][0] <= start; i++)
                end = max(end, clips[i][1]);
            if(start == end)
                return -1;
        }
        return ans;
    }
};
