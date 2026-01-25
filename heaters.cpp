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


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        long l = 0, r = max(heaters.back(), houses.back());
        long ans = 0;
        while(l <= r) {
            long m = l + (r - l) / 2;
            int i = 0;
            for(int heat : heaters) {
                while(i < houses.size() && heat - m <= houses[i] && heat + m >= houses[i]) {
                    i++;
                }
            }
            if(i == houses.size()) {
                ans = m;
                r = m - 1;
            }
            else 
                l = m + 1;
        }
        return ans;
    }
};
