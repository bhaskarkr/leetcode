class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0, maxIndex = 0, minEle = INT_MAX, maxEle = INT_MIN, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(minEle > nums[i]) 
                minEle = nums[i], minIndex = i;
            if(maxEle < nums[i]) 
                maxEle = nums[i], maxIndex = i;
        }
        if(minIndex > maxIndex)
            swap(minIndex, maxIndex);
        return min(maxIndex + 1, min(n - minIndex, minIndex + 1 + n - maxIndex));
    }
};

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0, maxIndex = 0, minEle = INT_MAX, maxEle = INT_MIN, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(minEle > nums[i]) 
                minEle = nums[i], minIndex = i;
            if(maxEle < nums[i]) 
                maxEle = nums[i], maxIndex = i;
        }
        return min(max(minIndex, maxIndex) + 1, min(n - min(minIndex, maxIndex), min(minIndex, maxIndex) + 1 + n - max(minIndex, maxIndex)));
    }
};
