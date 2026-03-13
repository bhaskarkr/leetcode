class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto a, auto b) {
            return a[1] < b[1];
        });
        int ans = 0;
        vector<bool> used(2001);
        for(auto task : tasks) {
            int s = task[0], e = task[1], d = task[2];
            for(int i = s; i <= e && d > 0; i++) {
                if(used[i])
                    d--;
            }
            while(e >= s && d > 0) {
                d -= !used[e];
                ans += !used[e];
                used[e] = true;
                e--;
            }
        }
        return ans;
    }
};
