class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniq;
        for(auto word : words) {
            string s = "";
            for(char c : word) {
                s += code[c - 'a'];
            }
            uniq.insert(s);
        }
        return uniq.size();
    }
};
