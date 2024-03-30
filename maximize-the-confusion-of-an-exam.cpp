class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t = 0, ans = 0;
        for(int l = 0, r = 0;  r < answerKey.length(); r++) {
            if(answerKey[r] == 'T')
                t++;
            while(r - l + 1 - t > k && t > k) {
                if(answerKey[l++] == 'T')
                    t--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
