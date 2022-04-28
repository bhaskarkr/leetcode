class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double, greater<int>> m; 
        for(int i = 0; i < position.size(); i++)
            m[position[i]] = (target*1.0 - position[i])/speed[i];
        double curr = 0;
        int ans = 0;
        for(auto [pos, time] : m) {
            if(time > curr) {
                curr = time;
                ans++;
            }
        }
        return ans;
    }
};
