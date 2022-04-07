class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> count(1002, 0);
        for(auto stone : stones)
            count[stone]++;
        int ans = 0;
        for(int i = 1000; i > 0; i--) {
            if(count[i] > 0 && count[i]%2) {
                int j = i - 1;
                while(j && count[j] == 0) {
                    j--;
                }
                if(j > 0) {
                    count[j]--;
                    count[i-j]++;
                    ans = 0;
                } else {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
