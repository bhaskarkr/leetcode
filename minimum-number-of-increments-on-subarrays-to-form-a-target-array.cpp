class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for(int i = 1; i < target.size(); i++)
            ans += max(target[i] - target[i-1], 0);
        return ans;
    }
};


class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> stk;
        int ans = 0;
        stk.push_back(0);
        for(int num : target) {
            if(stk.back() >= num)
                while(stk.back() >= num)
                    stk.pop_back();
            else if(stk.back() < num) {
                ans += num - stk.back();
            }
            stk.push_back(num);
        }
        return ans;
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for(int i = 1; i < target.size(); i++) {
            ans += target[i] > target[i-1] ? target[i] - target[i-1] : 0;
        }
        return ans;
    }
};
