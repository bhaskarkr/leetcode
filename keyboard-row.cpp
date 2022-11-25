class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> str = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;
        for(auto word : words) {
            
            for(auto line : str) {
                bool found = true;
                for(char c : word) {
                    if(line.find(tolower(c)) == string::npos) {
                        found = false;
                        break;
                    }
                }
                if(found) {
                    ans.push_back(word);
                    break;
                }
                
            }
           
        }
        return ans;
    }
};
