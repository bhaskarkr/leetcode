class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n)
            ans = max(ans, (c - '0')%10);
        return ans;
    }
};

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};
