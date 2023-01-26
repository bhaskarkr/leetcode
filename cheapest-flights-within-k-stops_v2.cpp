class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int edges = flights.size();
        vector< vector<pair<int,int> > > dis(n);
        for(auto& f : flights){
            dis[f[0]].push_back(make_pair(f[1],f[2]));
        }
        queue<vector<int> > Q;
        vector<int> costs(n, INT_MAX);
        Q.push({src, 0, -1});
        while(!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            if(curr[2] > K)
                continue;
            for(auto p : dis[curr[0]]){
                if(curr[2]+1 <= K && curr[1] + p.second < costs[p.first]){
                    costs[p.first] = curr[1] + p.second;
                    Q.push({p.first, curr[1] + p.second, curr[2]+1});
                }
            }
        }
        return costs[dst] != INT_MAX ? costs[dst] : -1;
        
    }
};
