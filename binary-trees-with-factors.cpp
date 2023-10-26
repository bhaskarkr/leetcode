class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> mp;
        sort(arr.begin(), arr.end());
        long long ans = 0;
        for(auto  k : arr) {
            mp[k] = 1;
            int half = (int)sqrt(k);
            int curr = 1;
            int index = upper_bound(arr.begin(), arr.end(), half) - arr.begin();
            for(int i = 0; i < index; i++) {
                int a = arr[i];
                int b = k / a;
                if( a* b == k) {
                    curr = (curr + (a == b ? 1 : 2) * mp[a]*mp[b]) % (1000000007);
                }
            }
            mp[k] = curr;
            ans = (curr + ans) % (1000000007);  
        }

        return ans;
    }
};
