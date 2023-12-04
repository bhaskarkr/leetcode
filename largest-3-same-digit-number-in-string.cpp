class Solution {
public:
    string largestGoodInteger(string num) {
        int m = -1;
        string ans = "";
        for(int i = 2; i < num.length(); i++) {
            if(num[i] - '0' > m && num[i] == num[i - 1] && num[i] == num[i-2]) {
                ans = string(3, num[i]);
                m = num[i] - '0';
            }
        } 
        return ans;
    }
};
