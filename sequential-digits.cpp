class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i = 1; i < 10; i++) q.push(i);
        while(!q.empty()) {
            int level = q.size();
            while(level--) {
                int curr = q.front();
                q.pop();
                if(curr > high)
                    continue;
                if(curr >= low)
                    ans.push_back(curr);
                if(curr % 10 < 9)
                    q.push(curr * 10 + (curr % 10 + 1));
            }
        }
        return ans;
    }
};
