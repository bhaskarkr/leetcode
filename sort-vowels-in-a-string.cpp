class Solution {
public:
    string sortVowels(string s) {
        map<char, int> counter;
        string sortedVowels, vowels = "AEIOUaeiou";
        for(char c : s)
            if(vowels.find(c) != string::npos)
                counter[c]++;
        for(auto [k, v] : counter)
            sortedVowels += string(v, k);
        for(int i = 0, j = 0; i < s.length(); i++) {
            if(vowels.find(s[i]) != string::npos)
                s[i] = sortedVowels[j++];
        }
        return s;
    }
};
