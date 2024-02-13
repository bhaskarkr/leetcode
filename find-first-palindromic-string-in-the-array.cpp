class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &word : words) {
            int i = 0, j = word.length() - 1;
            while(i < j && word[i] == word[j] && ++i && --j);
            if(i >= j)
                return word;
        }
        return "";
    }
};
