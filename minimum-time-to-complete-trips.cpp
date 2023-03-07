class Solution {
public:
    long long getSum(vector<int>& time, long long range) {
        long long sum = 0;
        for(int t : time) {
            sum += range/t;
        }
        return sum;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long l = time[0];
        long long r = (totalTrips*1L) * time[0];
        while(l < r) {
            long long m = (l + r) / 2;
            if(getSum(time, m) < totalTrips) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
