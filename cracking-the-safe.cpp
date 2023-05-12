class Solution {
public:
    string crackSafe(int n, int k) {
        string ans(n, '0');
        int totalPossibility = pow(k, n);
        unordered_set<string> visited;
        visited.insert(ans);
        helper(visited, ans, n, k, totalPossibility);
        return ans;
    }

    bool helper(unordered_set<string> &visited, string &ans, int &n, int &k, int &totalPossibility) {
        if(totalPossibility == visited.size())
            return true;
        for(int i = 0; i < k; i++) {
            ans += ('0' + i);
            string curr = ans.substr(ans.size() - n);
            if(visited.find(curr) == visited.end()) {
                visited.insert(curr);
                if(helper(visited, ans, n, k, totalPossibility))
                    return true;
                visited.erase(curr);
            }
            ans.pop_back();
        }
        return false;
    }
};
