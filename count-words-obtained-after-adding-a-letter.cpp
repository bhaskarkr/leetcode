class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<int> exists;
        for(string word : startWords) {
            int bitMask = 0;
            for(char c :  word) {
                bitMask |= 1 << (c - 'a');
            }
            exists.insert(bitMask);
        }
        int ans = 0;
        for(string word : targetWords) {
            for(int i = 0; i < word.length(); i++) {
                int j = 0;
                int bitMask = 0;
                for(char c :  word) {
                    if(i == j++)
                        continue;
                    bitMask |= 1 << (c - 'a');
                }
                if(exists.find(bitMask)  != exists.end()) {
                    ans++;
                    break;
                }
                    
            }
        }
        return ans;
    }
};
