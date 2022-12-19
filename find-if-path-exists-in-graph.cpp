class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adMat(n);
        vector<bool> visited(n);
        for(auto edge : edges) {
            adMat[edge[0]].push_back(edge[1]);
            adMat[edge[1]].push_back(edge[0]);
        }
        return dfs(n, adMat, source, destination, visited);
    }

    bool dfs(int n, vector<vector<int>>& edges, int source, int destination, vector<bool> &visited) {
        visited[source] = true;
        if(source == destination)
            return true;
        for(auto next : edges[source]) {
            if(!visited[next]) {
                if(dfs(n, edges, next, destination, visited))
                    return true;
            }
        }
        return false;
    }
};
