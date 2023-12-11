class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();
        int a = n / 4, b = n / 2, c = (3 * n) / 4;
        set<int> vals = {arr[a], arr[b], arr[c]};
        for(auto v : vals) {
            int it = prev(upper_bound(arr.begin(), arr.end(), v)) - arr.begin() - a;
            if(it >= 0 && arr[it] == v)
                return v;
        }
        return -1;
    }
};
