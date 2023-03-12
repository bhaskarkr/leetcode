class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 2;
        for(; i >= 0; i--)
            if(s[i] < s[i+1])
                break;
        if(i < 0)
            return -1;
        int j = i + 1;
        while(j + 1 < s.length() && s[j+1] > s[i]) {
            j++;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long temp = stol(s);
        if(temp > INT_MAX)
            return -1;
        return stoi(s);
    }
};
