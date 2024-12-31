class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses);
        for(auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> Q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0)
                Q.push(i);
        }
        int n = 0;
        while(!Q.empty()) {
            int c = Q.size();
            n += c;
            while(c--) {
                auto curr = Q.front();
                Q.pop();
                for(auto child : adjList[curr]) {
                    inDegree[child]--;
                    if(inDegree[child] == 0)
                        Q.push(child);
                }
            }
        }
        return n == numCourses;
    }
};
