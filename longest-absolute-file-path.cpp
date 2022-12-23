class Solution {
public:
    int lengthLongestPath(string input) {
        int level = 0, len = 0, ans = 0, isFile = false;
        input.push_back('\n');
        vector<int> wordsLen(400);
        for(char c : input) {
            if(c == '\n') {
                level = 0;
                len = 0;
                isFile = false;
            } else if(c == '\t') {
                level++;
            } else if(c == '.') {
                isFile = true;
                len++;
            } else {
                len++;
                wordsLen[level] = len;
                if(isFile)
                    ans = max(ans, accumulate(wordsLen.begin(), wordsLen.begin() + level + 1, 0) + level);
            }
        }
        return ans;
    }
};
