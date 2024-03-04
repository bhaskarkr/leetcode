class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int ans = 0, curr = 0, i = 0, j = tokens.size() - 1;
        while(i <= j) {
            while(i <= j && tokens[i] <= power)
                power -= tokens[i++], curr++;
            ans = max(ans, curr);
            if(curr > 0 && i < j)
                power += tokens[j--], curr--;
            else 
                break;
        }
        return ans;
    }
};

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int curr = 0;
        int ans = 0;
        while(i <= j) {
            if(tokens[i] <= power) {
                curr++;
                power -= tokens[i++];
            } else if(ans > 0) {
                curr--;
                power += tokens[j--];
            } else {
                break;
            }
            ans = max(ans, curr);
        }
        
        return ans;
    }
};



