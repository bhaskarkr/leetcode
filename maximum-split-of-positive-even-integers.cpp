class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum & 1)
            return ans;
        long long num = 2, currSum = 0;
        while(currSum + num <= finalSum) {
            ans.push_back(num);
            currSum += num;
            num += 2;
        }
        if(currSum < finalSum)
            ans.back() += finalSum - currSum;
        return ans;
    }
};
