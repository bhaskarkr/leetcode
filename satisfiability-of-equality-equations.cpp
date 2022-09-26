class Solution {
public:
    
    char findParent(char c, unordered_map<char, char> setId) {
        while(setId[c] != c)
            c = setId[c];
        return c;
    }
    
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> setId;
        for(char c = 'a'; c <= 'z'; c++) {
            setId[c] = c;
        }
        for(string s : equations) {
            if(s[1] == '=') {
                setId[findParent(s[3], setId)]  = findParent(s[0], setId);
            }
        }
        for(string s : equations) {
            if(s[1] == '!' && findParent(s[0], setId) == findParent(s[3], setId)) {
                return false;
            }
        }
        return true;
    }
};
