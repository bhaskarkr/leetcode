class Solution {
public:
    set<pair<int, int>> excep = {{1, 9}, {1, 7}, {1, 3}, {4, 6}, {7, 9}, {2, 8}, {3, 9}, {3, 7}};
    unordered_map<string, int> memo;
    string getKey(int m, int visited, int prev) {
        return to_string(m) + "_" + to_string(visited) + "_" + to_string(prev);
    } 
    int helper(int m, int visited, int prev) {
        if(m < 0)
            return 0;
        if(m == 0) {
            return 1;
        }
        string key = getKey(m, visited, prev);
        if(memo.find(key) != memo.end())
            return memo[key];
        int curr = 0;
        for(int i = 1; i <= 9; i++) {
            bool excepPair = excep.find({min(prev, i), max(prev, i)}) == excep.end();
            int midValue = (prev + i) / 2;
            bool middleVisited = (visited & (1 << midValue)) > 0;
            if((visited & (1 << i)) == 0 && (excepPair || middleVisited)) {
                visited = visited | (1 << i);
                curr += helper(m - 1, visited, i);
                visited = visited ^ (1 << i);
            }
        }
        return memo[key] = curr;
    }
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        for(int i = m; i <= n; i++) {
            ans += helper(i, 0, -1);
        }
        return ans;
    }
};
