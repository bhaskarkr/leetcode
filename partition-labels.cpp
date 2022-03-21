class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mapper;
        for(int i = 0; i < s.length(); i++) {
            if(mapper.find(s[i]) == mapper.end()) {
                mapper[s[i]] = {i, i};
            } else {
                mapper[s[i]].second = i;
            }
        }
        vector<pair<int, int>> vec;
        for(auto kv : mapper) {
            vec.push_back(kv.second);
        }
        sort(vec.begin(), vec.end());
        pair<int, int> prev = {-1, -1};
        vector<int> ans;
        for(auto curr : vec) {
            if(curr.first >  prev.second) {
                ans.push_back(curr.second - curr.first + 1);
                prev = curr;
            } else {
                ans.back() = ans.back() + max(prev.second, curr.second) - max(prev.second, curr.first);
                prev.second = max(prev.second, curr.second);
            }  
        }
        return ans;
    }
};
