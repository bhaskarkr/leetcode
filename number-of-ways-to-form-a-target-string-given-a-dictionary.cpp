class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<unordered_map<char, int>> counter(words[0].length());
        vector<vector<int>> DP(words[0].length(), vector<int>(target.length(), -1));
        for(string word : words) {
            for(int i = 0;i < word.length(); i++) {
                counter[i][word[i]]++;
            }
        }
        return helper(words, target, 0, 0, DP, counter);
    }

    long long helper(vector<string> &words, string &target, int i, int j, vector<vector<int>> &DP, vector<unordered_map<char, int>> &counter) {
        
        if(j >= target.length())
            return 1;
        if(i >= words[0].length()) 
            return 0;
        if(DP[i][j] != -1)
            return DP[i][j];
        long long considered = counter[i][target[j]]*helper(words, target, i+1, j+1, DP, counter);
        long long notConsidered =  helper(words, target, i+1, j, DP, counter);
        return DP[i][j] = (considered + notConsidered) % 1000000007;
    }
};
