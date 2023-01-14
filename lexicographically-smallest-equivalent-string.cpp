class Solution {
public:
    char getParent(unordered_map<char, char> &parent, char c) {
        while(parent[c] != c)
            c = parent[c];
        return c;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, char> parent;
        for(char c = 'a'; c <= 'z'; c++) {
            parent[c] = c;
        }
        for(int i = 0; i < s1.length(); i++) {
            char parent1 = getParent(parent, s1[i]);
            char parent2 = getParent(parent, s2[i]);
            if(parent1 < parent2) {
                parent[parent2] = parent1;
            } else {
                parent[parent1] = parent2;
            }
        }
        for(char &c : baseStr) {
            c = getParent(parent, c);
        }
        return baseStr;
    }
};
