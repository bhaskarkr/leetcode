class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> u;
        int ans = 1;
        for(int i = 0; i < source.length(); i++)
            u[source[i]].push_back(i);
        int curr = 0;
        for(int i = 0; i < target.length(); i++) {
            if(u.find(target[i]) == u.end())
                return -1;
            auto temp = lower_bound(u[target[i]].begin(), u[target[i]].end(), curr);
            if(temp == u[target[i]].end()) {
                ans++;
                curr = 0;
                temp = lower_bound(u[target[i]].begin(), u[target[i]].end(), curr);
            }
            curr = *temp + 1;
        }
        return ans;
    }
};
