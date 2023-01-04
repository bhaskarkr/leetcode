class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        for(int task : tasks)
            count[task]++;
        int ans = 0;
        for(auto [num, val] : count) {
            if(val == 1)
                return -1;
            ans += val/3 + (val%3 ? 1 : 0); 
        }
        return ans;
    }
};
