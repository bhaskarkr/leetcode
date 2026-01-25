class Solution {
public:
    int getParent(unordered_map<int, int> &parent, int curr) {
        if(curr == parent[curr]) 
            return curr;
        return parent[curr] = getParent(parent, parent[curr]);
    }

    void unionF(unordered_map<int, int> &parent, int x, int y) {
        int px = getParent(parent, x);
        int py = getParent(parent, y);
        if(px < py) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
        
    }
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, int> parent;
        int ans = 0;
        int maxE = *max_element(nums.begin(), nums.end());
        for(int i = 0; i <= maxE; i++) {
            parent[i] = i;
        }

        for(int num : nums) {
            for(int sq = 2; sq * sq <= num; sq++) {
                if(num % sq == 0) {
                    unionF(parent, num, sq);
                    unionF(parent, num, num / sq);
                }
            }
        }

        unordered_map<int, int> umap;
        for(int num : nums) {
            ans = max(ans, ++umap[getParent(parent, num)]);
        }

        return ans;
    }
};
