class Solution {
public:
    int getParent(int node, vector<int> &parent) {
        if(node == parent[node])
            return node;
        return getParent(parent[node], parent);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        using intpair = pair<int, int>;
        map<int, vector<intpair>> timeToMeeting;
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        parent[firstPerson] = 0;
        for(int i = 0; i < meetings.size(); i++)
            timeToMeeting[meetings[i][2]].push_back({meetings[i][0], meetings[i][1]});
        for(auto &meets : timeToMeeting) {
            for(auto &meet : meets.second) {
                int u = meet.first, v = meet.second;
                int pu = getParent(u, parent), pv = getParent(v, parent);
                parent[pv] = parent[pu] = min(pu, pv);
            }
            for(auto &meet : meets.second) {
                int u = meet.first, v = meet.second;
                int pu = getParent(u, parent), pv = getParent(v, parent);
                if(pu != 0 && pv != 0)
                    parent[u] = u, parent[v] = v;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(getParent(i, parent) == 0)
                ans.push_back(i);
        return ans;
    }
};
