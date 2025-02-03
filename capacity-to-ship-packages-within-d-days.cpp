class Solution {
public:
    bool isvalid(vector<int>& weights, int m, int days) {
        int count = 0, sum = 0;
        for(int i : weights) {
            if(sum + i > m) {
                count++;
                sum = 0;
            } 
            sum += i;
        }
        return count <= days - 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int l = max(sum / days, *max_element(weights.begin(), weights.end())), r = sum;
        while(l < r) {
            int m = l + (r-l) / 2;
            if(!isvalid(weights, m, days)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

};
