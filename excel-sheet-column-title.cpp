class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        columnNumber--;
        while(columnNumber >= 0) {
            ans += (columnNumber)%26 + 'A';
            columnNumber /= 26;
            columnNumber--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
