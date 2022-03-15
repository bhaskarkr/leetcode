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
            size_t filtered = s.substr(indices[i], k).find(sources[i]) ;
            if(filtered != string::npos) {
                s = s.substr(0, indices[i]) + targets[i] + s.substr(indices[i] + k); 
            }
        }
        return s;
    }
};
