class Solution {
public:
    unordered_map<int, vector<int>> tree;
    string ss;
    int longestPath(vector<int>& parent, string s) {
        vector<string> paths;
        int ans = 0;
        ss = s;
        for(int i = 1; i < parent.size(); i++) {
            tree[parent[i]].push_back(i);
        }
        helper(0, ans);
        return ans;
    }

    int helper(int curr, int &ans) {
        int max_len = 0;
        int second_max_len = 0;
        for(auto &child : tree[curr]) {
            int temp = helper(child, ans);
            if(ss[child] != ss[curr]) {
                if(max_len <= temp) {
                    second_max_len = max_len;
                    max_len = temp;
                } else if(temp > second_max_len) {
                    second_max_len = temp;
                }
            }
        }
        if(1 + second_max_len + max_len > ans)
            ans = 1 + second_max_len + max_len;
        return 1 + max_len;
    }
};
