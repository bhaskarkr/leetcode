class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size(), a = INT_MAX, b = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(wordsDict[i] == word1) {
                ans = min(ans, abs(b - i));
                a = i;     
            }
                
            if(wordsDict[i] == word2) {
                ans = min(ans, abs(a - i));
                b = i; 
            }
                
        }
        return ans;
    }
};
