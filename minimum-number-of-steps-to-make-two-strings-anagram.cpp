class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> cc;
        int ans = 0;
        for(char &c : s)
            cc[c]++;
        for(char &c : t)
            if(cc[c] > 0)
                cc[c]--;
        for(auto &[k, v] : cc) 
            ans += v;
        return ans;
    }
};
