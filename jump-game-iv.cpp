class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> positions;
        for( int i = 0; i < arr.size(); i++) {
            positions[arr[i]].push_back(i);
        }
        vector<bool> visited(n);
        queue<int> Q;
        Q.push(0);
        int ans = 0;
        visited[0] = true;
        while(!Q.empty()) {
            int count = Q.size();
            while(count--) {
                auto curr = Q.front();
                Q.pop();
                if(curr == n - 1)
                    return ans;
                if(curr + 1 < n && !visited[curr + 1]) {
                    Q.push(curr + 1);
                }
                if(curr - 1 >= 0 && !visited[curr - 1]) {
                    Q.push(curr - 1);
                }
                for(int child : positions[arr[curr]]) {
                    if(!visited[child]) {
                        Q.push(child);
                        visited[child] = true;
                    }
                }
                positions[arr[curr]].clear();
            }
            ans++;
        }

        return ans;
    }
};
