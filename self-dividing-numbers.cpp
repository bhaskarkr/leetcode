class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        while(left <= right) {
            int temp = left;
            while(temp) {
                int digit = temp % 10;
                if(digit == 0 || left % digit != 0) {
                    break;
                }
                temp /= 10;
            }
            if(temp == 0)
                ans.push_back(left);
            left++;
        }
        return ans;
    }
};
