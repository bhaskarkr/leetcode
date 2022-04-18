class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> umap;
        int ans = INT_MAX, sum = 0;
        umap[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            umap[sum] = i;
        }
        sum = 0;
        int firstSize = INT_MAX;
         for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(umap.find(sum - target) != umap.end()) {
                firstSize = min(firstSize, i - umap[sum - target]);
            }
            if(firstSize != INT_MAX && umap.find(sum + target) != umap.end()) {
                ans = min(ans, firstSize + umap[sum + target] - i);
            }  
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
