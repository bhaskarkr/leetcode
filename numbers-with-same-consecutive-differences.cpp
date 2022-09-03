class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> arr = {1,2,3,4,5,6,7,8,9};
        for(int j = 1; j < n; j++) {
            unordered_set<int> temp(arr.begin(), arr.end());
            arr.clear();
            for(auto val : temp) {
                int lastDigit = val%10;
                int nextUp = lastDigit + k;
                int nextDown = lastDigit - k;
                if(nextUp < 10)
                    arr.insert(val*10 + nextUp);
                if(nextDown >= 0)
                    arr.insert(val*10 + nextDown);    
            }
        }
        vector<int> ans(arr.begin(), arr.end());
        return ans;
    }
};
