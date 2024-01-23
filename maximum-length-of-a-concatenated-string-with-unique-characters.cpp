class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bits;
        for(string &s : arr) {
            int k = 0;
            set<char> unq(s.begin(), s.end());
            if(unq.size() != s.length())
                continue;
            for(char c : s)
                k |= (1 << (c - 'a'));
            bits.push_back(k);
        }
        int ans = 0;
        for(int i = 1; i < (1 << bits.size()); i++) {
            int temp = 0;
            bool valid = true;
            for(int index = 0; index < bits.size(); index++) {
                if(!((1 << index) & i))
                    continue;
                if(bits[index] & temp) {
                    valid = false;
                    break;
                }
                temp |= bits[index];
            }
            if(valid)
                ans = max(ans, __builtin_popcount(temp));
        }
        return ans;
    }
};


class Solution {
public:
    int ans;
    void finder(int index, vector<int>& bits, int select) {
        if(index == bits.size()) {
            ans = max(ans, __builtin_popcount(select));
            return;
        }
        if((select & bits[index]) == 0)
            finder(index + 1, bits, select | bits[index]);
        finder(index + 1, bits, select);
    }
    int maxLength(vector<string>& arr) {
        vector<int> bits;
        for(string &s : arr) {
            int k = 0;
            set<char> unq(s.begin(), s.end());
            if(unq.size() != s.length())
                continue;
            for(char c : s)
                k |= (1 << (c - 'a'));
            bits.push_back(k);
        }
        finder(0, bits, 0);
        return ans;
    }
};
