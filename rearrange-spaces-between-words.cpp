class Solution {
public:
    string reorderSpaces(string text) {
        int len = text.length();
        int wordlength = 0;
        stringstream ss(text);
        string temp;
        vector<string> words;
        string ans;
        while(getline(ss, temp, ' ')) {
            if(temp.length()) {
                words.push_back(temp);
                wordlength += temp.length();
            }
        }
        if(words.size() < 2)
            return words.empty() ? "" : words.back() + string((len - wordlength), ' ');
        int spaces = (len - wordlength) / (words.size() - 1);
        ans = words[0];
        for(int i = 1; i < words.size(); i++) {
            ans += string(spaces, ' ') + words[i];
        }
        ans += string((len - wordlength) % (words.size() - 1) , ' ');
        return ans;
    }
};
