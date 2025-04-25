class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<long long> modulos(nums.size());
        unordered_map<long long, int> umap;
        long long ans = 0;
        umap[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            modulos[i] = (nums[i] % modulo) == k ? 1 : 0;
            if(i)
                modulos[i] += modulos[i - 1];
            modulos[i] %= modulo;
            ans += umap[(modulos[i] - k + modulo) % modulo];
            umap[modulos[i]]++;
        }
        return ans;
    }
};
