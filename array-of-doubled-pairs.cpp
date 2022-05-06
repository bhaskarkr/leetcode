class Solution {
public:
    static bool comparator(int &a, int &b) {
        return abs(a) < abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        int unmatched = 0;
        int n = arr.size();
        unordered_map<int, int> umap;
        for(auto num : arr)
            umap[num]++;
        vector<int> keys;
        for(auto [k,v] : umap)
            keys.push_back(k);
        sort(keys.begin(), keys.end(), comparator);
        for(int k : keys) {
            if(umap[k] > umap[2*k])
                return false;
            umap[2*k] -= umap[k];
        }
        return true;
    }
    
    
//     bool canReorderDoubled(vector<int>& arr) {
//         sort(arr.begin(), arr.end(), comparator);
//         int unmatched = 0;
//         int n = arr.size();
//         unordered_map<int, int> umap;
//         for(int i = 0; i < n; i++) {
//             if(umap[2*arr[n - i - 1]] > 0) {
//                 umap[2*arr[n - i - 1]]--;
//                 unmatched--;
//             } else {
//                 umap[arr[n - i -1]]++;
//                 unmatched++;
//             }
                
//         }
//         return unmatched == 0;
//     }
    
};
