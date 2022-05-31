class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> uset;
        deque<char> DQ;
        for(char c : s) {
            DQ.push_back(c);
            if(DQ.size() == k) {
                uset.insert({DQ.begin(), DQ.end()});
                DQ.pop_front();
            }
        }
        return uset.size() == 1 << k;
    }
};
