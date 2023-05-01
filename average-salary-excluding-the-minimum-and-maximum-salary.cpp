class Solution {
public:
    double average(vector<int>& salary) {
        int maxV = salary.back(), minV = salary.back(), sum = 0;
        for(int num : salary) {
            sum += num;
            maxV = max(maxV, num);
            minV = min(minV, num);
        }
        return (sum - maxV - minV)/(salary.size() - 2.0);

    }
};
