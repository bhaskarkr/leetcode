class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        target.insert(target.begin(), 0);
        for(int i = 1; i < target.size(); i++) {
            int d = target[i] - target[i-1] - 1;
            while(d--) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int c = 0, k = 1;
        vector<string> ans;
        while(c < target.size() && k <= n) {
            ans.push_back("Push");
            if(k == target[c]) {
                c++;
            } else {
                ans.push_back("Pop");
            }
            k++;
        }
        return ans;
    }
};
