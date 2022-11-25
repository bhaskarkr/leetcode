class Solution {
public:
    
    string getUpper(string input) {
        for(char &c : input)
            c = toupper(c);
        return input;
    }
    
    string getLower(string input) {
        for(char &c : input)
            c = tolower(c);
        return input;
    }
    
    bool detectCapitalUse(string word) {
        return getUpper(word) == word || getLower(word) == word || (toupper(word[0]) && getLower(word.substr(1)) == word.substr(1));
     }
};
