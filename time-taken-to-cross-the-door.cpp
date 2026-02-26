class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int enter = 0, exit = 0, n = arrival.size(), prev = -1, t = 0;
        vector<int> ans(n);
        while(enter < n || exit < n) {
            while(enter < n && state[enter] != 0) {
                enter++;
            }
            while(exit < n && state[exit] != 1) {
                exit++;
            }
            if(enter >= n && exit >= n)
                break;
            if(enter >= n && arrival[exit] <= t) {
                ans[exit] = t;
                exit++;
            } else if(exit >= n && arrival[enter] <= t) {
                ans[enter] = t;
                enter++;
            } else if(enter < n && exit < n) {
                if(arrival[enter] <= t && arrival[exit] <= t) {
                    if(prev != 0) {
                        ans[exit] = t;
                        prev = 1;
                        exit++;
                    } else {
                        ans[enter] = t;
                        prev = 0;
                        enter++;
                    }
                } else if(arrival[enter] <= t) {
                    ans[enter] = t;
                    prev = 0;
                    enter++;
                } else if (arrival[exit] <= t) {
                    ans[exit] = t;
                    prev = 1;
                    exit++;
                } else {
                    prev = -1;
                }
            }
            t++;
        }
        return ans;
    }
};
