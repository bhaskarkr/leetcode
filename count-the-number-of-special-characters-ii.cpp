class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        unordered_map<char, int> indices;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == tolower(word[i]))
                indices[word[i]] = i;
            if(word[i] == toupper(word[i]) && indices.find(word[i]) == indices.end())
                indices[word[i]] = i;
        }
        unordered_set<char> unq;
        for(int i = word.length() - 1; i >= 0; i--) {
            if(word[i] == tolower(word[i]) && indices[word[i]] < indices[toupper(word[i])])
                ans++, unq.insert(word[i]);
        }
        return unq.size();
    }
};
