class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
    
    string helper(string s, int& index) {
        string decoded = "";
        while(index < s.length() && s[index] != ']') {
            if(!isdigit(s[index]))
                decoded+=s[index++];
            else {
                int num = 0;
                while(isdigit(s[index])) {
                    num = num*10 + (s[index] - '0');
                    index++;
                }
                index++;
                string temp = helper(s, index);
                index++;
                while(num--)
                    decoded += temp;
            }
        }
        return decoded;
    }
};
