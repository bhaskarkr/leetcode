class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> indegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);  
                ans.push_back(i);
            }  
        }
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(auto rec : m[curr]) {
                indegree[rec]--;
                if(indegree[rec] == 0) {
                    q.push(rec);
                    ans.push_back(rec);
                }
            }
        }
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
    stack<int> stk;
    unordered_set<int> alreadyInStack;
    bool dfs(int curr, unordered_set<int> visited, unordered_map<int, vector<int>> &adj) {
        bool ans = true;
        visited.insert(curr);
        for(int child : adj[curr]) {
            if(visited.find(child) != visited.end() || !dfs(child, visited, adj))
                return false;
        }
        if(alreadyInStack.find(curr) == alreadyInStack.end()) {
            alreadyInStack.insert(curr);
            stk.push(curr);
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses), ans;
        unordered_map<int, vector<int>> adj;
        for(auto pre : prerequisites) {
            inorder[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        unordered_set<int> visited;
        for(int i = 0; i < numCourses; i++) {
            if(inorder[i] == 0 && !dfs(i, visited, adj)) {
                return {}; 
            }
        }
        if(stk.size() != numCourses)
            return {};
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
