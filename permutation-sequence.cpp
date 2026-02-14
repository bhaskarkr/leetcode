class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        long fact = 1;
        vector<int> nums;
        for(int i = 1; i < n; i++)
            fact *= i, nums.push_back(i);
        nums.push_back(n);
        k--;
        while(1) {
            cout<<k / fact<<endl;
            int idx = (k / fact);
            s += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact;
            if(nums.empty())
                break;
            fact /= nums.size();
        }
        return s;
    }
};
