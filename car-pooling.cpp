class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> vec(1e5 + 1);
        for(auto trip : trips) {
            vec[trip[1]]+= trip[0];
            vec[trip[2]] -= trip[0];
        }
        for(int i = 0; i < vec.size(); i++) {
            vec[i] += i == 0 ? 0 : vec[i-1];
            if(vec[i] > capacity)
                return false;
        }
        return true;
    }
};
