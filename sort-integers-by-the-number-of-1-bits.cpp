class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int num : arr)
            count[num] = __builtin_popcount(num);
        sort(arr.begin(), arr.end(), [&](auto a, auto b){
            if(count[a] == count[b])
                return a < b;
            return count[a] < count[b];
        });
        return arr;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](auto a, auto b){
            int x = __builtin_popcount(a);
            int y = __builtin_popcount(b);
            return x == y ? a < b : x < y;
        });
        return arr;
    }
};
