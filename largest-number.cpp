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


class Solution {
public:
    string largestNumber(vector<int> nums) {
        auto lambda = [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        };
        sort(nums.begin(), nums.end(), lambda);
        string ans;
        for(auto n : nums)
            ans += to_string(n);
        unordered_set<char> uset(ans.begin(), ans.end());
        return uset.size() == 1 and *uset.begin() == '0' ? "0" : ans;
    }
};
