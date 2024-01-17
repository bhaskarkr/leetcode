class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        vector<int> c(arr.size() + 1);
        for(int &a : arr) {
            umap[a]++;
        }
        for(auto &[k,v]: umap) {
            if(c[v])
                return false;
            c[v]++;
        }
        return true;
    }
};


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int ele : arr) {
            count[ele]++;
        }
        set<int> visited;
        for(auto [k,v] : count) {
            if(visited.find(v) != visited.end())
                return false;
            visited.insert(v);
        }
        return true;
    }
};
