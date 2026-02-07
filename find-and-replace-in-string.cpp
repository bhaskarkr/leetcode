class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>> sortedIndices;
        for(int i = 0; i < indices.size(); i++) {
            sortedIndices.push_back({indices[i], i});
        }
        sort(sortedIndices.begin(), sortedIndices.end(), greater<pair<int,int>>());
        for(int j = 0; j < indices.size(); j++) {
            int i = sortedIndices[j].second;
            int k = sources[i].length();
            size_t searchIndex = s.substr(indices[i], k).find(sources[i]) ;
            if(searchIndex != string::npos) {
                s = s.substr(0, indices[i]) + targets[i] + s.substr(indices[i] + k); 
            }
        }
        return s;
    }
};


class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<tuple<int, string, string>> inp;
        for(int i = 0; i < n; i++)
            inp.push_back(make_tuple(indices[i], sources[i], targets[i]));
        sort(inp.begin(), inp.end());
        for(int i = n - 1; i >= 0; i--) {
            auto [index, source, target] = inp[i];
            if(index + source.length() <= s.length() && s.substr(index, source.length()) == source)
                s = s.substr(0, index) + target + s.substr(index + source.length());
        }
        return s;
    }
};
