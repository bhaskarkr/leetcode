class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> umap;
        int sum = 0, ans = 0;
        umap[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if(umap.find(sum) == umap.end())
                umap[sum] = i;
            else
                ans = max(ans, i - umap[sum]);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            sum += num == 1 ? 1 : -1;
            if(umap.find(sum) == umap.end()) {
                umap[sum] = i;
            } else {
                ans = max(ans, i - umap[sum]);
            }
        }
        return ans;
    }
};
