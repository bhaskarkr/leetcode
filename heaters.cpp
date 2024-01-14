class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long ans = 0;
        sort(heaters.begin(), heaters.end());
        for(long house : houses) {
            int index = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            if(index == 0) {
                ans = max(ans, abs(house - heaters[0]));
            } else if(index == heaters.size()) {
                ans = max(ans, abs(house - heaters.back()));
            } else {
                long left = abs(house - heaters[index - 1]);
                ans = max(ans, min(left, abs(house - heaters[index])));
            }
        }
        return ans;
    }
};
