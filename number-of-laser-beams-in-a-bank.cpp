class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = -1;
        for(string s : bank) {
            int curr = count(s.begin(),s.end(),'1');
            if(curr) {
                ans += prev != -1 ? prev * curr : 0;
                prev = curr;
            }
        }
        return ans;
    }
};
