class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> atob;
        if(str1 == str2)
            return true;
        for(int i = 0; i < str1.length(); i++) {
            if(atob.find(str1[i]) != atob.end() && atob[str1[i]] != str2[i]) {
                return false;
            }
            atob[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};
