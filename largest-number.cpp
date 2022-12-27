class Solution {
public:
    static bool cmp(string &a, string &b) {
        return b + a > a + b;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(int i : nums)
            num.push_back(to_string(i)); 
        sort(num.rbegin(), num.rend(), cmp);
        string ans = "";
        for(string s : num) 
            ans += s;
        return ans[0] == '0'? "0" : ans ;
    }
};
