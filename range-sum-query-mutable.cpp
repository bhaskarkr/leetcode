class NumArray {
public:
    vector<int> BIT;
    vector<int> nums;
    int n;
    NumArray(vector<int>& num) {
        n = num.size();
        nums = num;
        BIT = vector<int>(n + 5, 0);
        for(int i = 0; i < n; i++) {
            addValue(i, num[i]);
        }
    }
    
    void addValue(int index, int val) {
        index++;
        while(index <= n) {
            BIT[index] += val;
            index += (index & -index);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index] ;
        nums[index] = val;
        addValue(index, diff);
    }
    
    int getSum(int index) {
        index++;
        int sum = 0;
        while(index > 0) {
            sum += BIT[index];
            index -= (index & -index);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
