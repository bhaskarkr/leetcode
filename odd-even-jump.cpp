class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> upper(n), lower(n);
        map<int, int> traversed;
        int ans = 1;
        traversed[arr.back()] = n - 1;
        upper.back() = lower.back() = true;
        for(int i = n - 2; i >= 0; i--) {
            auto ub = traversed.upper_bound(arr[i]);
            auto lb = traversed.lower_bound(arr[i]);
            if(lb != traversed.end())
                upper[i] = lower[lb->second];
            if(ub != traversed.begin())
                lower[i] = upper[prev(ub)->second];
            if(upper[i])
                ans++;
            traversed[arr[i]] = i;
        }
        return ans;
    }
};
