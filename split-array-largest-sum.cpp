class Solution {
public:
    
    bool checkIfPossible(int subArraySum, vector<int> & nums, int subArrayCount) {
        int currSum = 0;
        for(auto num : nums) {
            if(currSum + num <= subArraySum) {
                currSum += num;
            } else {
                subArrayCount--;
                currSum = num;
                if(subArrayCount <= 0)   {
                    return false;
                }
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for(auto num : nums) {
            right += num;
            left = max(num, left);
        }
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(checkIfPossible(mid, nums, m)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    } 
};
