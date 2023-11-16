class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s = string(nums[0].length(), '0');
        sort(nums.begin(), nums.end());
        for(string k : nums) {
            if(s == k) {
                int j = s.length() - 1;
                while(j >= 0 && s[j] == '1')
                    s[j--] = '0';
                if(j >= 0)
                    s[j] = '1';   
            } else
                return s;
        }
        return s;
    }
};
