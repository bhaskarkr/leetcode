class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        set<char> visited;
        stringstream ss(s);
        string temp;
        int index = 0;
        while(getline(ss, temp, ' ')) {
            if(index >= pattern.length() || umap.find(temp) != umap.end() || visited.count(pattern[index])) {
                if(index >= pattern.length() || pattern[index] != umap[temp]) 
                    return false;
            } else {
                visited.insert(pattern[index]);
                umap[temp] = pattern[index];
            }
            index++;
        }
        return index == pattern.length();
    }
};
