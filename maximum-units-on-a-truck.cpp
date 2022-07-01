class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];  
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans = 0;
        for(auto boxType : boxTypes) {
            ans += min(boxType[0], truckSize)*boxType[1];
            truckSize -= min(boxType[0], truckSize);
            if(!truckSize)
                return ans;
        }
        return ans;
    }
};
